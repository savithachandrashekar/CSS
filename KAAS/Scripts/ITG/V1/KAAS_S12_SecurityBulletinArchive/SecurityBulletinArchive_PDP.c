SecurityBulletinArchive_PDP()
{	
	web_set_sockets_option("SSL_VERSION","TLS1.2");
	
	lr_save_string(lr_eval_string("{cp_WCCAccessToken}"), "WCCAccessToken");
	web_add_header("accessToken","{WCCAccessToken}");
	
	//{"matches":[{"documentID
	web_reg_find("Text={\"matches\":[{\"documentID", "SaveCount=Text_count", LAST);
		
	lr_start_transaction("KAAS_T029_SecurityBulletinArchive");
	
	web_custom_request("web_custom_request",
	    "URL=https://hx9ekpvvbi.execute-api.us-east-1.amazonaws.com/KaaS-ITG/v2/search?q=*&resultLimit=1000&resultStart=0&languageCode=en&countryCode=162089707212699946554652&store=udp-content-default,docstore&contentTypes=Security Bulletin",
		"Method=GET",
		"TargetFrame=",
		"Resource=0",
		"Referer=",
		"Body=",
		LAST);
	
	if(strcmp(lr_eval_string("{Text_count}"),"0")==0)
	{
		lr_end_transaction("KAAS_T029_SecurityBulletinArchive", LR_FAIL);

	}
	else
	{
		lr_end_transaction("KAAS_T029_SecurityBulletinArchive", LR_PASS);

	}

	//lr_end_transaction("KAAS_T029_SecurityBulletinArchive", LR_AUTO);
	
	return 0;
}
