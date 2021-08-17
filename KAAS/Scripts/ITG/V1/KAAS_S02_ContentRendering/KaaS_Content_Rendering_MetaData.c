KaaS_Content_Rendering_MetaData()
{
	
	web_set_sockets_option("SSL_VERSION","TLS1.2");
	
	lr_save_string(lr_eval_string("{cp_WISEAccessToken}"), "cp_WISEAccessToken");
	web_add_header("Content-Type","application/x-www-form-urlencoded");
	web_add_header("accessToken","{cp_WISEAccessToken}");
	
	web_reg_find("Text=script", "SaveCount=Text_count", LAST);
	
	lr_start_transaction("KAAS_T005_MetaData_Content_Rendering");
	
	web_custom_request("web_custom_request",
		"URL=https://hx9ekpvvbi.execute-api.us-east-1.amazonaws.com/KaaS-ITG/v2/search?documentID={p_CRMetaData}&resultLimit=1&resultStart=0&languageCode=ko,en&countryCode=6984892597308500812593&store=udp-content-default,docstore,manualstore,sdlmanualstore&printFields=documentID,filename,name,summary,objectname,dredbname,description,title,shortestnavigationpath,categorizations,ishType,searchable,languagedocmap",
		"Method=GET",
		"TargetFrame=",
		"Resource=0",
		"Referer=",
		"Body=",
		LAST);

	
	if(strcmp(lr_eval_string("{Text_count}"),"0")==0)
    {
        lr_end_transaction("KAAS_T005_MetaData_Content_Rendering", LR_FAIL);

    }
    else
    {
        lr_end_transaction("KAAS_T005_MetaData_Content_Rendering", LR_PASS);

    }
	
	//lr_end_transaction("KAAS_T005_MetaData_Content_Rendering", LR_AUTO);
	
	return 0;
}
