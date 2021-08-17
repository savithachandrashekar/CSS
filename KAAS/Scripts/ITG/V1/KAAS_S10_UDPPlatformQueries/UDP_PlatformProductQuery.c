UDP_PlatformProductQuery()
{
	web_set_sockets_option("SSL_VERSION","TLS1.2");
	web_add_header("Content-Type","application/x-www-form-urlencoded");
	
	lr_save_string(lr_eval_string("{cp_WISEAccessToken}"), "WISEAccessToken");
	web_add_header("accessToken","{WISEAccessToken}");
	
	//matches":[{"terms":
	web_reg_find("Text=matches\":[{\"terms\":", "SaveCount=Text_count", LAST);
	
	lr_start_transaction("KAAS_T021_UDP_PlatformProductQuery");
	
	web_custom_request("web_custom_request",
	"URL=https://hx9ekpvvbi.execute-api.us-east-1.amazonaws.com/KaaS-ITG/v2/search?q=Gamora 1.0 OMN&languageCode=en&store=tmsstore,tmsfuturestore,tmsplatformstore&minScore=1&filters=shallincludeinautosuggest:true AND contenttype:Product&resultLimit=20&printFields=body,title,class,tmspmseriesvalue,tmspmnamevalue,tmspmnumbervalue,score,productid,childnodes,tmsnodedepth,platformmodels;",
		"Method=GET",
		"TargetFrame=",
		"Resource=0",
		"Referer=",
		"Body=",
		LAST);
	
	if(strcmp(lr_eval_string("{Text_count}"),"0")==0)
	{
		lr_end_transaction("KAAS_T021_UDP_PlatformProductQuery", LR_FAIL);

	}
	else
	{
		lr_end_transaction("KAAS_T021_UDP_PlatformProductQuery", LR_PASS);

	}
	
	
	//lr_end_transaction("KAAS_T021_UDP_PlatformProductQuery", LR_AUTO);
	
	return 0;
}
