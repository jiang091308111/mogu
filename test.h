#ifndef __TEST_H__
#define __TEST_H__
#include <foundation/ckit_thread.h>
#include <foundation/ckit_time.h>
#include <map>
#include "metric.h"
#include "log_analysis.h"
#include "handle_message.h"
#include "read_config.h"
using namespace ckit;
using namespace std;

class Test: public Thread
{
public:
	Test():iMaxMapSize(60)
	{
		m_ReadConfig.OpenFile("cpc_mearch.json");
		m_ReadConfig.GetCpcMsearchConfig(vec1,vec2,vec3);
		for(int i=0;i<vec1.size();i++)
		{
			std::cout<<"11111111"<<vec1[i]<<std::endl;
			std::cout<<"22222222"<<vec2[i]<<std::endl;
			std::cout<<"33333333"<<vec3[i]<<std::endl;
		}
		m_MessageSend.SetAppName("cpc_msearch_test");
	}
	~Test()
	{
	}
	void SetMaxMapSize(int num)
	{
		iMaxMapSize = num;
	}
	virtual void Run();
	void Process(const string& strip,const string& strlog);
	void CountLog(const string& strlog,map<string,map<int,int> >& mapcount);
	void SendLog();
	void QpsAlarm();
	void RtAlarm(const string ip, int value);
	void SearchFaildAlarm(const string ip, int value);
	void SearchDiscardAlarm(const string ip, int value);
	string GetCurrentTime()
	{
		time_t tmp = ckit::time::GetCurrentSecond();
		return ckit::time::ToString(tmp);
	}
private:
	Metric m_Metric;
	MessageSend m_MessageSend;
	ReadConfig m_ReadConfig;
	vector<string> vec1,vec2;
	vector<int> vec3,vec4;//vec3储存着报警阀门，vec4保存了10分钟的平均值
	map<string,map<string,map<int,int> > > m_DataType;
	int iMaxMapSize;
};

#endif

