vuser_init()
{
	
	web_set_sockets_option("SSL_VERSION","TLS1.2");
	
	web_add_header("Authorization","Basic V0lTRTpHZTRFSDllN1VoMVpkZzRnbjhCSmtXOHVtUVhNblBmSnJCNHFZeTJLV3oyVFJBTWw1eFlVVVRSaU5kNW9zbERq");
	web_add_header("Content-Type", "application/x-www-form-urlencoded");
	web_add_header("Host","login-itg.external.hp.com");
	web_reg_save_param("cp_WISEAccessToken", "LB=access_token\":\"", "RB=\",\"token_type", LAST);
	
	web_custom_request("web_custom_request",
		"URL=https://login-itg.external.hp.com/as/token.oauth2?grant_type=client_credentials",
		"Method=POST",
		"TargetFrame=",
		"Resource=0",
		"Referer=",
		"Body=",
		LAST);
	
	
	
	return 0;
}
