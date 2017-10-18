#include <stdio.h>
#include <iostream>
#include <fstream>
#include "AlgorithmUnitManage.h"
static int encode_reqeust_brief_alg_unit(std::string& json_str)
{
	slothjson::alg_unit_brief_request_t req;

	req.request.cmd = "Command_Algorithm_Srv_Get_Info";

	slothjson::alg_unit_req_brief_t  req_brief;

	req_brief.refid = "detected_v1.2";
	req_brief.cate = "trafic";

	req.request.algo_info.push_back(req_brief);

	req_brief.refid = "detected_v1.3";
	req_brief.cate = "trafic";

	req.request.algo_info.push_back(req_brief);
	
	req.encode_to_string(json_str);

	return 0;	
}

static int decode_reqeust_brief_alg_unit(const std::string& json_str,slothjson::alg_unit_brief_request_t& req)
{
	req.decode_from_string(json_str);

	return 0;	
}

static int encode_response_brief_alg_unit(std::string& json_str)
{
	slothjson::alg_unit_brief_response_t  resp;

	resp.err_code = 0;
	resp.err_msg = "success";
	resp.cmd =  "Command_Algorithm_Srv_Get_Info";
	slothjson::alg_unit_t alg_info;
	
	alg_info.algid = "100023";
	alg_info.cate = "traffic";
	alg_info.comb_pos = 1;
	alg_info.file_name = "/usr/local/vion/alg1";
	alg_info.name = "detect";
	alg_info.note = "traffic vehicle detect";
	alg_info.refid = "detcted_v1.2";
	alg_info.version = "1.2";
	alg_info.unid = "bb24321321338";
	alg_info.upload_dt = "201709123T12:04:23 223";

	resp.response.algo_info.push_back(alg_info);

	alg_info.algid = "100024";
	alg_info.cate = "traffic";
	alg_info.comb_pos = 1;
	alg_info.file_name = "/usr/local/vion/alg1";
	alg_info.name = "detect";
	alg_info.note = "traffic vehicle detect";
	alg_info.refid = "detcted_v1.3";
	alg_info.version = "1.3";
	alg_info.unid = "bb24321321335";
	alg_info.upload_dt = "201709123T18:04:23 223";
	resp.response.algo_info.push_back(alg_info);
	resp.encode_to_string(json_str);

	return 0;	
}


static int decode_response_brief_alg_unit(const std::string& json_str,slothjson::alg_unit_brief_response_t& resp)
{
	resp.decode_from_string(json_str);
	return 0;	
}

int main() 
{
	std::string req1_str;
	encode_reqeust_brief_alg_unit(req1_str);
	std::cout<<req1_str<<std::endl;
	std::string resp1_str;
	encode_response_brief_alg_unit(resp1_str);
	std::cout<<resp1_str<<std::endl;

	slothjson::alg_unit_brief_request_t req1;
	decode_reqeust_brief_alg_unit(req1_str,req1);

	slothjson::alg_unit_brief_response_t resp1;
	decode_response_brief_alg_unit(resp1_str,resp1);

	getchar();
	return 0;
}
