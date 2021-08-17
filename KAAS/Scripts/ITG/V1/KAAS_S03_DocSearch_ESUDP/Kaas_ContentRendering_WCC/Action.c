Action()
{
	//int iIsSearchDone = 0;
	web_set_sockets_option("SSL_VERSION","TLS1.2");
	web_add_header("Content-Type","application/x-www-form-urlencoded");
	//web_add_header("accessToken","8KQxVFvygEmCCczdkGLQTwkyps2j");
	
	//Duplicate this script
	lr_start_transaction("KAAS_Content_Rendering_WCC");	
	web_custom_request("web_custom_request",
		"URL=https://hx9ekpvvbi.execute-api.us-east-1.amazonaws.com/KaaS-ITG/v2/render/000asg0XCpVjXDJRsVo6B8JY5NYR/{p_ContentRendering}?entitlement=none&audience=customer&isFullHTMLRequired=true",
		"Method=GET",
		"TargetFrame=",
		"Resource=0",
		"Referer=",
		//"Body=",
		LAST);
	lr_end_transaction("KAAS_Content_Rendering_WCC",LR_AUTO);
	
	return 0;
}
