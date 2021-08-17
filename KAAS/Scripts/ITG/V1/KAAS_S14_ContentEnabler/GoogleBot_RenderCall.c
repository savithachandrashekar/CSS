GoogleBot_RenderCall()
{
	
	web_set_sockets_option("SSL_VERSION","TLS1.1");
	
	lr_save_string(lr_eval_string("{cp_WISEAccessToken}"), "WISEAccessToken");
	web_add_header("accessToken","{WISEAccessToken}");
	
	web_reg_find("Text=script", "SaveCount=Text_count", LAST);
	
	lr_start_transaction("KAAS_T035_GoogleBot_RenderCall");
	
	web_custom_request("web_custom_request",
	    "URL=https://hx9ekpvvbi.execute-api.us-east-1.amazonaws.com/KaaS-ITG/v2/render/{WISEAccessToken}/{p_ISH_Doc_GoogleBot}?entitlement=highValue",
	    "Method=GET",
		"TargetFrame=",
		"Resource=0",
		"Referer=",
		"Body=",
		LAST);

	
	if(strcmp(lr_eval_string("{Text_count}"),"0")==0)
	{

		lr_end_transaction("KAAS_T035_GoogleBot_RenderCall", LR_FAIL);
   
	}
    else
    {
        lr_end_transaction("KAAS_T035_GoogleBot_RenderCall", LR_PASS);
    }
    
	//lr_end_transaction("KAAS_T035_GoogleBot_RenderCall", LR_AUTO);
	
	return 0;
}
