Kaas_TypeAhead_Printers()
{

	web_set_user("elastic", "changeme", "{p_hostname}");  	
	lr_start_transaction("TA_004_Kaas_TypeAhead_Printers");

	web_set_sockets_option("SSL_VERSION","TLS1.2");
	web_add_header("Content-Type","application/x-www-form-urlencoded");
	
	//web_add_header("accessToken","000aCTFyIs3SM9SoNoRIyyIQNvCM");
	web_custom_request("web_custom_request",
		"URL=https://{p_hostname}/suggestions/search/?q={p_TypeAheadPrintFields}&resultLimit=10&store=tmsstore&languageCode=en&filters=class:(pm_series_value%5E1.1%20OR%20pm_name_value%20OR%20pm_number_value) AND navigationpath:268161584258236861743175748903686 &printFields=tmspmnamevalue,title,body,childnodes,class,productid,seofriendlyname,shortestnavigationpath",
		"Method=GET",
		"TargetFrame=",
		"Resource=0",
		"Referer=",
		"Body=",
		LAST);

	lr_end_transaction("TA_004_Kaas_TypeAhead_Printers", LR_AUTO);
	return 0;
}
