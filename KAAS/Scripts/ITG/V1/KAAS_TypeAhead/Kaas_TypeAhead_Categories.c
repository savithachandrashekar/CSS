Kaas_TypeAhead_Categories()
{
	
	web_add_header("Content-Type","application/x-www-form-urlencoded");
	//web_add_header("Authorization","Basic ZWxhc3RpYzpjaGFuZ2VtZQ==");
	
	lr_start_transaction("TA_003_Kaas_TypeAhead_Categories");
	web_set_user("elastic", "changeme", "{p_hostname}");  
	
	web_custom_request("web_custom_request",
		"URL=https://{p_hostname}/suggestions/search?q={p_TypeAhead_Categories}&resultLimit=20&resultStart=0&store=tmsstore&language=en&filters=navigationpath:({p_TypeAhead_Cat_Param2})",
		"Method=GET",
		"TargetFrame=",
		"Resource=0",
		"Referer=",
		"Body=",
		LAST);

	lr_end_transaction("TA_003_Kaas_TypeAhead_Categories", LR_AUTO);
	return 0;
}
