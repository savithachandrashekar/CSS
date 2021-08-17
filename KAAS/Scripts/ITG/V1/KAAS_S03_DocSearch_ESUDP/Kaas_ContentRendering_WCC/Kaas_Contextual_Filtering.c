Kaas_Contextual_Filtering()
{
	web_set_sockets_option("SSL_VERSION","TLS1.2");
	web_add_header("Content-Type","application/x-www-form-urlencoded");
	
	
	lr_start_transaction("KAAS_Contextual_Filtering");
	
	web_custom_request("web_custom_request",
		//"URL=https://hx9ekpvvbi.execute-api.us-east-1.amazonaws.com/KaaS-ITG/v2/render/qMf4LMKvhxUS90P1hbKXiTsjDJcj/{p_DocID}?conditions=FHPIPRODUCT={p_productID}",
		"URL=https://hx9ekpvvbi.execute-api.us-east-1.amazonaws.com/KaaS-ITG/v2/render/000aqIhNR9X1TRdnQ66Usa4QswCJ/{p_DocID}?conditions=FHPIPRODUCT={p_productID}",
		"Method=GET",
		"TargetFrame=",
		"Resource=0",
		"Referer=",
		//"Body=",
		LAST);
	
	lr_end_transaction("KAAS_Contextual_Filtering", LR_AUTO);

	return 0;
}
