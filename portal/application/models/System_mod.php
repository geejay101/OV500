<?php
// ##############################################################################
// OV500 - Open Source SIP Switch & Pre-Paid & Post-Paid VoIP Billing Solution
//
// Copyright (C) 2019-2020 Chinna Technologies   
// Seema Anand <openvoips@gmail.com>
// Anand <kanand81@gmail.com>
// http://www.openvoips.com  http://www.openvoips.org
//
// OV500 Version 1.0.1
// License https://www.gnu.org/licenses/agpl-3.0.html
//
// The Initial Developer of the Original Code is
// Anand Kumar <kanand81@gmail.com> & Seema Anand <openvoips@gmail.com>
// Portions created by the Initial Developer are Copyright (C)
// the Initial Developer. All Rights Reserved.
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Affero General Public License as
// published by the Free Software Foundation, either version 3 of the
// License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU Affero General Public License for more details.
//
// You should have received a copy of the GNU Affero General Public License
// along with this program. If not, see <http://www.gnu.org/licenses/>.
// ##############################################################################

class System_mod extends CI_Model {

    public $did_id;
    public $total_count;

    function __construct() {
        parent::__construct();
        $this->load->database();
    }

    function get_data_total_count() {
        return $this->total_count;
    }

  
    function get_proxy_server_data() {
        $final_return_array = array();
        try {
            $logged_user_type = get_logged_account_type();
            $logged_user_account_id = get_logged_account_id();
            $logged_user_level = get_logged_account_level();


            $sql = "select 'PROXY' km, loadbalancer as lbaddress, count(id) calls , sum(if(callstatus ='answer',1,0)) as anscalls from livecalls WHERE 1 ";

            if (check_logged_account_type(array('RESELLER'))) {
                if ($logged_user_level == 1) {
                    $sql .= " AND reseller1_account_id ='" . $logged_user_account_id . "'  ";
                } elseif ($logged_user_level == 2) {
                    $sql .= " AND reseller2_account_id ='" . $logged_user_account_id . "'  ";
                } else {
                    $sql .= " AND reseller3_account_id ='" . $logged_user_account_id . "'  ";
                }
            }

            $sql .= " GROUP BY lbaddress";

            
            $query = $this->db->query($sql);

            if (!$query) {
                $error_array = $this->db->error();
                throw new Exception($error_array['message']);
            }

            foreach ($query->result_array() as $row) {
                $final_return_array['result'][] = $row;
            }

            $final_return_array['status'] = 'success';
            $final_return_array['message'] = 'Servers fetched successfully';

            return $final_return_array;
        } catch (Exception $e) {
            $final_return_array['status'] = 'failed';
            $final_return_array['message'] = $e->getMessage();
            return $final_return_array;
        }
    }

    function get_switch_server_data() {
        $final_return_array = array();
        try {
            $sql = "select 'SWITCH' km, fs_host, count(id) calls   , sum(if(callstatus ='answer',1,0)) as anscalls from livecalls GROUP BY fs_host";
      
            $query = $this->db->query($sql);

            if (!$query) {
                $error_array = $this->db->error();
                throw new Exception($error_array['message']);
            }

            foreach ($query->result_array() as $row) {
                $final_return_array['result'][] = $row;
            }

            $final_return_array['status'] = 'success';
            $final_return_array['message'] = 'Servers fetched successfully';

            return $final_return_array;
        } catch (Exception $e) {
            $final_return_array['status'] = 'failed';
            $final_return_array['message'] = $e->getMessage();
            return $final_return_array;
        }
    }

    function get_proxy_switch_server_data() {
        $final_return_array = array();
        try {
            $sql = "select concat('PROXY (',loadbalancer,')') proxy, concat('SWITCH (',fs_host,')') switch, count(id) calls , sum(if(callstatus ='answer',1,0)) as anscalls from livecalls GROUP BY loadbalancer, fs_host;";
            
          
            $query = $this->db->query($sql);

            if (!$query) {
                $error_array = $this->db->error();
                throw new Exception($error_array['message']);
            }

            foreach ($query->result_array() as $row) {
                $final_return_array['result'][] = $row;
            }

            $final_return_array['status'] = 'success';
            $final_return_array['message'] = 'Servers fetched successfully';

            return $final_return_array;
        } catch (Exception $e) {
            $final_return_array['status'] = 'failed';
            $final_return_array['message'] = $e->getMessage();
            return $final_return_array;
        }
    }

    function get_proxy_customer_calls_data() {
        $final_return_array = array();
        try {

            $sql = "SELECT livecalls.loadbalancer lbaddress,concat(livecalls.customer_company,' (',livecalls.customer_account_id,')') AS company, livecalls.customer_ipaddress user_ip,count(livecalls.id) calls , sum(if(callstatus ='answer',1,0)) as anscalls from livecalls GROUP BY loadbalancer, customer_account_id, customer_ipaddress ORDER BY calls desc";

            $query = $this->db->query($sql);

            if (!$query) {
                $error_array = $this->db->error();
                throw new Exception($error_array['message']);
            }

            foreach ($query->result_array() as $row) {
                $final_return_array['result'][] = $row;
            }

            $final_return_array['status'] = 'success';
            $final_return_array['message'] = 'Customers calls date fetched successfully';

            return $final_return_array;
        } catch (Exception $e) {
            $final_return_array['status'] = 'failed';
            $final_return_array['message'] = $e->getMessage();
            return $final_return_array;
        }
    }

}
