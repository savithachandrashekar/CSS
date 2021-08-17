KaaS_Content_Rendering_MetaData()
{
	
	web_set_sockets_option("SSL_VERSION","TLS1.2");
	web_add_header("Content-Type","application/x-www-form-urlencoded");
	web_add_header("accessToken","000aqIhNR9X1TRdnQ66Usa4QswCJ");
	
	lr_start_transaction("KAAS_MetaData_Content_Rendering");
	
	web_custom_request("web_custom_request",
		"URL=https://hx9ekpvvbi.execute-api.us-east-1.amazonaws.com/KaaS-ITG/v2/search?documentID={p_CR_MetaData}&resultLimit=1&resultStart=0&languageCode=ko,en&countryCode=6984892597308500812593&store=udp-content-default,docstore,manualstore,sdlmanualstore&printFields=documentID,filename,name,summary,objectname,dredbname,description,title,shortestnavigationpath,categorizations,ishType,searchable,languagedocmap",
		"Method=GET",
		"TargetFrame=",
		"Resource=0",
		"Referer=",
		"Body=",
		LAST);

	
	lr_end_transaction("KAAS_MetaData_Content_Rendering", LR_AUTO);
	
	return 0;
}
