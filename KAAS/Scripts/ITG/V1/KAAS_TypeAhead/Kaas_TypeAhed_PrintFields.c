Kaas_TypeAhed_PrintFields()
{
	web_set_user("elastic", "changeme", "{p_hostname}");  	
	
	web_reg_find("Text={\"matches\":", "SaveCount=Text_count", LAST);
	lr_start_transaction("TA_002_TypeAhead_PrintFields");

	
	//web_reg_find("text=title",LAST);
	web_add_header("Content-Type","application/x-www-form-urlencoded");
	//web_add_header("Authorization","Basic ZWxhc3RpYzpjaGFuZ2VtZQ==");


	web_custom_request("web_custom_request",
		"URL=https://{p_hostname}/suggestions/search?q={p_TypeAheadPrintFields}&resultLimit=20&resultStart=0&store=tmsstore&language=en&printFields=title,body,childnodes,productid,class,tmspmnumbervalue,tmspmnamevalue,tmspmseriesvalue,seofriendlyname",
		"Method=GET",
		"TargetFrame=",
		"Resource=0",
		"Referer=",
		"Body=",
		LAST);

	
	if(strcmp(lr_eval_string("{Text_count}"),"0")==0)
	{
		lr_end_transaction("TA_002_TypeAhead_PrintFields", LR_FAIL);

	}
	else
	{
		lr_end_transaction("TA_002_TypeAhead_PrintFields", LR_PASS);

	}
	
	
	//lr_end_transaction("TA_002_TypeAhead_PrintFields", LR_AUTO);
	
	return 0;
}
