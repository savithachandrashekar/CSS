kaas_DocSearchHPES_Promotion_query()
{
	
	web_set_sockets_option("SSL_VERSION","TLS1.2");

	lr_save_string(lr_eval_string("{c_WISEAccessToken}"), "WISEAccessToken");	
	web_add_header("accessToken","{WISEAccessToken}");
	web_add_header("Content-Type","application/x-www-form-urlencoded");
	
	 web_reg_find("Text=took", "SaveCount=Text_count", LAST);
	
	lr_start_transaction("KAAS_HPES_Promotion");
	web_custom_request("web_custom_request",
		"URL=https://hx9ekpvvbi.execute-api.us-east-1.amazonaws.com/KaaS-ITG/v2/search?q={p_PromotionQuery}&resultLimit=15&resultStart=0&languageCode=en&countryCode=us&promotions=true&store=promotions&filters=products:(NONE)%20AND%20NOT%20publicationdestination:(FindMyProduct)",
		"Method=GET",
		"TargetFrame=",
		"Resource=0",
		"Referer=",
		"Body=",
		LAST);
	
	 if(strcmp(lr_eval_string("{Text_count}"),"0")==0)
	{
		lr_end_transaction("KAAS_HPES_Promotion", LR_FAIL);

	}
	else
	{
		lr_end_transaction("KAAS_HPES_Promotion", LR_PASS);

	}
  
	//lr_end_transaction("KAAS_HPES_Promotion",LR_AUTO);
	
	return 0;
}
