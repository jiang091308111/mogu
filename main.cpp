#include <kafka/ckit_kafka.h>
#include <iostream>
#include "test.h"
#include "handle_message.h"
using namespace ckit;
using namespace std;
//SingleLogQueue g_SingleLogQueue;
int main()
{
	//ckit::log::SetPrintLogger();
	HandleMessage myHMess0,myHMess1,myHMess2,myHMess3;
	myHMess0.SetTopicConf("topic.offset.store.method", "file");
	myHMess0.SetTopicConf("topic.offset.store.sync.interval.ms", "1");
	myHMess0.SetTopicConf("auto.commit.interval.ms", "10");
	myHMess0.SetTopicConf("group.id","g1");
	myHMess0.SetOffset(RD_KAFKA_OFFSET_END);
	myHMess0.SetTopic("msearch_cpc");
	myHMess0.SetPartition(0);
	std::cout<<"11111111111"<<std::endl;
	myHMess1.SetTopicConf("topic.offset.store.method", "file");
	myHMess1.SetTopicConf("topic.offset.store.sync.interval.ms", "1");
	myHMess1.SetTopicConf("auto.commit.interval.ms", "10");
	myHMess1.SetTopicConf("group.id","g2");
	myHMess1.SetOffset(RD_KAFKA_OFFSET_END);
	myHMess1.SetTopic("msearch_cpc");
	myHMess1.SetPartition(1);
	std::cout<<"2222222222"<<std::endl;
	myHMess2.SetTopicConf("topic.offset.store.method", "file");
	myHMess2.SetTopicConf("topic.offset.store.sync.interval.ms", "1");
	myHMess2.SetTopicConf("auto.commit.interval.ms", "10");
	myHMess2.SetTopicConf("group.id","g3");
	myHMess2.SetOffset(RD_KAFKA_OFFSET_END);
	myHMess2.SetTopic("msearch_cpc");
	myHMess2.SetPartition(2);
	std::cout<<"333333333"<<std::endl;
	myHMess3.SetTopicConf("topic.offset.store.method", "file");
	myHMess3.SetTopicConf("topic.offset.store.sync.interval.ms", "1");
	myHMess3.SetTopicConf("auto.commit.interval.ms", "10");
	myHMess3.SetTopicConf("group.id","g4");
	myHMess3.SetOffset(RD_KAFKA_OFFSET_END);
	myHMess3.SetTopic("msearch_cpc");
	myHMess3.SetPartition(3);
	std::cout<<"4444444444"<<std::endl;
	myHMess0.Start();
	myHMess0.Join();
	myHMess1.Start();
	myHMess1.Join();
	myHMess2.Start();
	myHMess2.Join();
	myHMess3.Start();
	myHMess3.Join();

	std::cout<<"123456789"<<std::endl;
	Test myConsumer;
	myConsumer.Start();
	myConsumer.Join();
	while(1)
	{
		sleep(1); 
	} 
}
