kaas_DocSearchHPES_Product_Context()
{
	
	
	
	lr_save_string(lr_eval_string("{c_WISEAccessToken}"), "WISEAccessToken");
	web_add_header("Content-Type","application/x-www-form-urlencoded");
	web_add_header("accessToken","{WISEAccessToken}");
	
	lr_start_transaction("HPES_ProductContext");
	
	web_custom_request("web_custom_request",
		"URL=https://hx9ekpvvbi.execute-api.us-east-1.amazonaws.com/KaaS-ITG/v2/search?q={p_ProductContext}&resultLimit=20&resultStart=0&languageCode=en&countryCode=us&store=tmsstore&filters=(shallincludeinautosuggest:true%20AND%20class:(pm_series_value%5E2%20OR%20pm_name_value%20OR%20pm_number_value)%20AND%20contenttype:Product)",
		"Method=GET",
		"TargetFrame=",
		"Resource=0",
		"Referer=",
		"Body=",
		LAST);
	
	lr_end_transaction("HPES_ProductContext",LR_AUTO);
	
	return 0;
}
