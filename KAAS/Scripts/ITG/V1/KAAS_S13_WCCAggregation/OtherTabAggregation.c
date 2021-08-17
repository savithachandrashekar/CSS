OtherTabAggregation()
{
	web_set_sockets_option("SSL_VERSION","TLS1.2");
	lr_save_string(lr_eval_string("{cp_WCCAccessToken}"), "WCCAccessToken");
	web_add_header("accessToken","{WCCAccessToken}");
	
	web_reg_find("Text=matches", "SaveCount=Text_count", LAST);	
	lr_start_transaction("KAAS_T032_OtherTabAggregation");
	
	web_custom_request("web_custom_request",
		"URL=https://hx9ekpvvbi.execute-api.us-east-1.amazonaws.com/KaaS-ITG/v2/search?q=*&resultLimit=1&resultStart=0&languageCode=en&countryCode=162089707212699946554652&store=udp-content-default,docstore,sdlmanualstore,manualstore&product={p_productID}&aggregations=esmanuals,documenttype",
		"Method=GET",
		"TargetFrame=",
		"Resource=0",
		"Referer=",
		"Body=",
		LAST);
	
	if(strcmp(lr_eval_string("{Text_count}"),"0")==0)
	{
		lr_end_transaction("KAAS_T032_OtherTabAggregation", LR_FAIL);

	}
	else
	{
		lr_end_transaction("KAAS_T032_OtherTabAggregation", LR_PASS);

	}
	
//	lr_end_transaction("KAAS_T032_OtherTabAggregation", LR_AUTO);
	
	return 0;
}
