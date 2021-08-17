BatchSearch_EmptyIssueSignature()
{
	//lr_save_string(lr_eval_string("{????????cp_IssueBatchAccessToken}????????"), "IssueBatchAccessToken");
	
	web_set_sockets_option("SSL_VERSION", "TLS1.2");
	
	lr_save_string(lr_eval_string("{cp_IssueBatchAccessToken}"), "IssueBatchAccessToken");
	web_add_header("accessToken","{IssueBatchAccessToken}");
	web_add_header("Content-Type","application/json");
	
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
		"                    \"44.16.0B\",\n"
		"                    \"15.F2.E0\"\n"
		"                ],\n"
		"                \"action\": \"TriageHDDBoot\"\n"
		"            },\n"
		"            \"productSignature\": [\"F2A68A%\"],\n"
		"            \"disclosureLevel\": [\"47406819852170807613486806879990\"]\n"
		"        },\n"
		"        {\n"
		"            \"issueSignature\": {\n"
		"            },\n"
		"            \"disclosureLevel\": [\"696531864679532034919979251200881\",\"47406819852170807613486806879990\"]\n"
		"        },\n"
		"        {\n"
		"            \"issueSignature\": {\n"
		"                \"eco\": [\n"
		"                    \"44.16.0B#\",\n"
		"                    \"15.F2.E0\"\n"
		"                ]\n"
		"            },\n"
		"            \"product\": [\n"
		"                \"5118062\"\n"
		"            ],\n"
		"            \"disclosureLevel\": [\"696531864679532034919979251200881\",\"47406819852170807613486806879990\"]\n"
		"        },\n"
		"        {\n"
		"            \"issueSignature\": {\n"
		"                \"eco\": [\n"
		"                    \"44.16.0B\",\n"
		"                    \"15.F2.E0\"\n"
		"                ]\n"
		"            },\n"
		"             \"disclosureLevel\": [\"696531864679532034919979251200881\",\"47406819852170807613486806879990\"]\n"
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
	//lr_end_transaction("KAAS_T020_IssueBatchSearch", LR_AUTO);
	return 0;
}
