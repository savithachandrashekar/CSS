UDP_PlatformContentQueries()
{
	
	web_set_sockets_option("SSL_VERSION","TLS1.2");
	lr_save_string(lr_eval_string("{cp_WISEAccessToken}"), "WISEAccessToken");
	web_add_header("accessToken","{WISEAccessToken}");
	
	//{"matches":[{"documentID":
	web_reg_find("Text=\"matches\":[{\"documentID\"", "SaveCount=Text_count", LAST);
	
	lr_start_transaction("KAAS_T022_UDP_PlatformContentQuery");


	web_submit_data("web_submit_data",
		"Action=https://hx9ekpvvbi.execute-api.us-east-1.amazonaws.com/KaaS-ITG/v2/search?",
		"Method=GET",
		"TargetFrame=",
		"Referer=",
		"Mode=HTML",
		ITEMDATA,
		"Name=q", "Value=*", ENDITEM,
		"Name=resultLimit", "Value=10", ENDITEM,
		"Name=resultStart", "Value=0", ENDITEM,
		"Name=filters", "Value=(audience:commercial OR (!_exists_:audience)) AND (processagentlevel:(LVL1 OR LVL0 OR _ALL) OR (!_exists_:processagentlevel))", ENDITEM,
		"Name=regionCode", "Value=145557537553804145623571,145969036451726883647975,212299498967880112552079", ENDITEM,
		"Name=languageCode", "Value=en", ENDITEM,
		"Name=fromDate", "Value=1900-01-01", ENDITEM,
		"Name=toDate", "Value=2020-09-08", ENDITEM,
		"Name=disclosureLevel", "Value=696531864679532034919979251200881,47406819852170807613486806879990,218620138892645155286800249901443,287477763180518087286275037723076,887243771386204747508092376253257", ENDITEM,
		"Name=startTag", "Value=<strong>", ENDITEM,
		"Name=endTag", "Value=</strong>", ENDITEM,
		"Name=printFields", "Value=documentID,title,documenttype,contentupdatedate,languagecode,disclosurelevel,store,filename", ENDITEM,
		"Name=store", "Value=docstore,supportagentstore,udp-content-default,manualagentstore,manualstore,sdlmanualstore,videostore,processagentstore", ENDITEM,
		"Name=platform", "Value=4168912-80-100", ENDITEM,
		"Name=aggregations", "Value=esstores", ENDITEM,
		"Name=excludeContentTypes", "Value=error message", ENDITEM,
		"Name=searchable", "Value=true", ENDITEM,
		LAST);

		if(strcmp(lr_eval_string("{Text_count}"),"0")==0)
		{
		lr_end_transaction("KAAS_T022_UDP_PlatformContentQuery", LR_FAIL);

	}
	else
	{
		lr_end_transaction("KAAS_T022_UDP_PlatformContentQuery", LR_PASS);

	}
	
	//lr_end_transaction("KAAS_T022_UDP_PlatformContentQuery", LR_AUTO);
	

	return 0;
}
