BatchSearch_SingleRequest()
{
	//Single Request
	//issue batch search queries use WCC/HPI access token
		
	web_set_sockets_option("SSL_VERSION", "TLS1.1");
	
	lr_save_string(lr_eval_string("{cp_IssueBatchAccessToken}"), "IssueBatchAccessToken");
	web_add_header("accessToken","{IssueBatchAccessToken}");
	web_add_header("Content-Type","application/json");
	
	//{"matches":[{"documentID":
	web_reg_find("Text=\"matches\":[{\"documentID\"", "SaveCount=Text_count", LAST);
	
	lr_start_transaction("KAAS_T020_IssueBatchSearch");
	
	
	web_custom_request("web_custom_request",
		"URL=https://hx9ekpvvbi.execute-api.us-east-1.amazonaws.com/KaaS-ITG/v2/issueBatch/search",
		"Method=POST",
		"TargetFrame=",
		"Resource=0",
		"Referer=",
		"Body={\n"
		"    \"languageCode\": \"en\",\n"
		"    \"countryCode\": \"162089707212699946554652\",\n"
		"    \"printFields\": [\n"
		"        \"countrycode\",\n"
		"        \"issuesignature\",\n"
		"        \"requiredtools\",\n"
		"        \"time\",\n"
		"        \"partnumber\",\n"
		"        \"skilllevel\",\n"
		"        \"title\",\n"
		"        \"description\"\n"
		"    ],\n"
		"    \"requests\": [\n"
		"        {\n"
		"            \"issueSignature\": {\n"
		"                \"eco\": [\n"
		"                    \"15.F2.E0\"\n"
		"                ],\n"
		"                \"action\": \"replaceFormatter\"\n"
		"            },\n"
		"            \"disclosureLevel\":[ \"696531864679532034919979251200881\",\"287477763180518087286275037723076\",\"218620138892645155286800249901443\",\"47406819852170807613486806879990\",\"887243771386204747508092376253257\"]\n"
		"        }\n"
		"    ]\n"
		"}",
		LAST);
	
	if(strcmp(lr_eval_string("{Text_count}"),"0")==0)
	{
		lr_end_transaction("KAAS_T020_IssueBatchSearch", LR_FAIL);

	}
	else
	{
		lr_end_transaction("KAAS_T020_IssueBatchSearch", LR_PASS);

	}

//	lr_end_transaction("KAAS_T020_IssueBatchSearch", LR_AUTO);
	
	return 0;
}
