#ifndef JSON_TR_HEADER_______
#define JSON_TR_HEADER_______
#include <string>
struct	_PRMemDBBlock_;
typedef	struct	_PRMemDBBlock_	tagPRBlock;
namespace Json {
	class Value;
};

namespace PRAdequacyBase {
	struct _BpaPRAdequacySetting_;
	typedef struct _BpaPRAdequacySetting_ tagBpaPRAdequacySetting;
};

namespace json_tr {
	std::string	FormResultJSon(const char* lpszCommand, const char* lpszRetValue, const char* lpszMesg);
	void FormRecordJSon(tagPRBlock* pPRBlock, const int nTable, const int nRecord, Json::Value& sField);
	std::string	FormResultJSon(tagPRBlock* pPRBlock, const char* lpszMesg, const int nEstimateState);

	void ParsePRSetting(Json::Value& sData, PRAdequacyBase::tagBpaPRAdequacySetting* pSetting);
};

#endif // !JSON_TR_HEADER_______
