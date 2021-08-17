WISE_KaasContentRendering()
{
	
	web_set_sockets_option("SSL_VERSION","TLS1.2");
	
	lr_save_string(lr_eval_string("{cp_WISEAccessToken}"), "cp_WISEAccessToken");
	web_add_header("Content-Type","application/x-www-form-urlencoded");
		
	web_reg_find("Text=script", "SaveCount=Text_count", LAST);
	
	
	lr_start_transaction("KAAS_T002_Content_Rendering");	
	
	web_custom_request("web_custom_request",
		"URL=https://hx9ekpvvbi.execute-api.us-east-1.amazonaws.com/KaaS-ITG/v2/render/{cp_WISEAccessToken}/{p_ContentRendering}",
		"Method=GET",
		"TargetFrame=",
		"Resource=0",
		"Referer=",
		//"Body=",
		LAST);
	
	if(strcmp(lr_eval_string("{Text_count}"),"0")==0)
    {
        lr_end_transaction("KAAS_T002_Content_Rendering", LR_FAIL);

    }
    else
    {
        lr_end_transaction("KAAS_T002_Content_Rendering", LR_PASS);

    }
	//lr_end_transaction("KAAS_T002_Content_Rendering",LR_AUTO);
	
	return 0;
}
