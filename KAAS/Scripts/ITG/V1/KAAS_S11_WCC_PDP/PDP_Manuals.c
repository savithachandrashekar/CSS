PDP_Manuals()
{
	lr_save_string(lr_eval_string("{cp_WCCAccessToken}"), "WCCAccessToken");
	web_set_sockets_option("SSL_VERSION","TLS1.1");
	web_add_header("accessToken","{WCCAccessToken}");
	
	//web_reg_find("Text=\"matches\":[{\"documentID\"", "SaveCount=Text_count", LAST);
	web_reg_find("Text=\"matches\":[", "SaveCount=Text_count", LAST);
	
	lr_start_transaction("KAAS_T026_PDP_Manuals");
	
	web_custom_request("web_custom_request",
		"URL=https://hx9ekpvvbi.execute-api.us-east-1.amazonaws.com/KaaS-ITG/v2/search?q=*&resultLimit=1000&resultStart=0&languageCode=en&countryCode=162089707212699946554652&product={p_productID}&store=manualstore,sdlmanualstore&printFields=topics,topIssue,filesize,cve",
		"Method=GET",
		"TargetFrame=",
		"Resource=0",
		"Referer=",
		"Body=",
		LAST);
	
	
	
	if(strcmp(lr_eval_string("{Text_count}"),"0")==0)
	{
		lr_end_transaction("KAAS_T026_PDP_Manuals", LR_FAIL);

	}
	else
	{
		lr_end_transaction("KAAS_T026_PDP_Manuals", LR_PASS);

	}
	
	//lr_end_transaction("KAAS_T026_PDP_Manuals", LR_AUTO);
	
	return 0;
}
