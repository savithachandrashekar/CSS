DocSearchHPES_FindMyProduct_200()
{	
	web_add_header("Content-Type","application/x-www-form-urlencoded");
	lr_save_string(lr_eval_string("{cp_WISEAccessToken}"), "WISEAccessToken");
	web_add_header("accessToken","{WISEAccessToken}");
	web_reg_find("Text=matches", "SaveCount=Text_count", LAST);
	
	
	lr_start_transaction("KAAS_T018_DocSearchHPES_FindMyProduct_200");
	web_custom_request("web_custom_request",
		"URL=https://hx9ekpvvbi.execute-api.us-east-1.amazonaws.com/KaaS-ITG/v2/search?q={p_FindMyProduct}&resultLimit=200&resultStart=0&languageCode=en&countryCode=us&store=tmsstore&filters=(class:(pm_series_value%5E1.5%20OR%20pm_name_value%20OR%20pm_number_value)%20AND%20contenttype:Product%20AND%20historicalwebsupportflag:(no))&clientId=WCC",
		"Method=GET",
		"TargetFrame=",
		"Resource=0",
		"Referer=",
		"Body=",
		LAST);
	
	if(strcmp(lr_eval_string("{Text_count}"),"0")==0)
    {
        lr_end_transaction("KAAS_T018_DocSearchHPES_FindMyProduct_200", LR_FAIL);

    }
    else
    {
        lr_end_transaction("KAAS_T018_DocSearchHPES_FindMyProduct_200", LR_PASS);

    }
    
	//	lr_end_transaction("KAAS_T018_DocSearchHPES_FindMyProduct_200",LR_AUTO);
	return 0;
}
