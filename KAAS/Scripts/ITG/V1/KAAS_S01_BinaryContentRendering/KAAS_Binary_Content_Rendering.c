KAAS_T001_BinaryContentRendering()
{
	web_set_sockets_option("SSL_VERSION","TLS1.1");
	
	
	web_reg_save_param("Response", "LB=", "RB=",  LAST);
		
	lr_start_transaction("KAAS_T001_BinaryContentRendering");
	
	web_custom_request("web_custom_request",
		"URL=https://hx9ekpvvbi.execute-api.us-east-1.amazonaws.com/KaaS-ITG/v2/renderbinary/{p_BinaryContent}",
		"Method=GET",
		"TargetFrame=",
		"Resource=0",
		"Referer=",
		"Body=",
		LAST);

	if(strcmp(lr_eval_string("{Response}"),"")==0)
    {
        lr_end_transaction("KAAS_T001_BinaryContentRendering", LR_FAIL);

    }
    else
    {
        lr_end_transaction("KAAS_T001_BinaryContentRendering", LR_PASS);

    }
	//lr_end_transaction("KAAS_T001_BinaryContentRendering", LR_AUTO);
	
	
	return 0;
}
