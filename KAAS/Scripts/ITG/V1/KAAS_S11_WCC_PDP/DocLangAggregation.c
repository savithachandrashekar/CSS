DocLangAggregation()
{
	web_set_sockets_option("SSL_VERSION","TLS1.2");
	web_add_header("accessToken","{WCCAccessToken}");
	
	web_reg_find("Text={\"matches\":[],\"range\":{", "SaveCount=Text_count", LAST);
	
	lr_start_transaction("DocLangAggregation");
	//11461069
	web_custom_request("web_custom_request",
		"URL=https://hx9ekpvvbi.execute-api.us-east-1.amazonaws.com/KaaS-ITG/v2/search?q=*&resultLimit=0&resultStart=0&languageCode=fr,en&store=manualstore,sdlmanualstore&product={p_productID}&printFields=fileSize,filename,sourceGUID,colId,hpid&aggregations=disclosurelevel,doclanguages",
		"Method=GET",
		"TargetFrame=",
		"Resource=0",
		"Referer=",
		"Body=",
		LAST);
	
	if(strcmp(lr_eval_string("{Text_count}"),"0")==0)
	{
		lr_end_transaction("DocLangAggregation", LR_FAIL);

	}
	else
	{
		lr_end_transaction("DocLangAggregation", LR_PASS);

	}
	
	//lr_end_transaction("DocLangAggregation", LR_AUTO);
	
	return 0;
}
