WCC_KaasContentRendering()
{
	
	web_set_sockets_option("SSL_VERSION","TLS1.2");
	
	lr_save_string(lr_eval_string("{cp_WCCAccessToken}"), "WCCAccessToken");
	web_add_header("Content-Type","application/x-www-form-urlencoded");
	
	
	web_reg_find("Text=script", "SaveCount=Text_count", LAST);
	
	
	lr_start_transaction("KAAS_T003_Content_Rendering_WCC");	
	web_custom_request("web_custom_request",
		"URL=https://hx9ekpvvbi.execute-api.us-east-1.amazonaws.com/KaaS-ITG/v2/render/{WCCAccessToken}/{p_ContentRendering_WCC}?entitlement=none&audience=customer&isFullHTMLRequired=true",
		"Method=GET",
		"TargetFrame=",
		"Resource=0",
		"Referer=",
		//"Body=",
		LAST);
	
	if(strcmp(lr_eval_string("{Text_count}"),"0")==0)
    {
        lr_end_transaction("KAAS_T003_Content_Rendering_WCC", LR_FAIL);

    }
    else
    {
        lr_end_transaction("KAAS_T003_Content_Rendering_WCC", LR_PASS);

    }
//	lr_end_transaction("KAAS_T003_Content_Rendering_WCC",LR_AUTO);
	
	return 0;
}
