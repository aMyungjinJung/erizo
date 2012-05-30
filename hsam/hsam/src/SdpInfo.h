/*
 * SDPProcessor.h
 *
 *  Created on: Mar 14, 2012
 *      Author: pedro
 */

#ifndef SDPINFO_H_
#define SDPINFO_H_

#include <string>
#include <vector>

enum hostType{
	HOST,
	SRLFX,
	PRFLX,
	RELAY
};

enum mediaType{
	VIDEO_TYPE,
	AUDIO_TYPE,
	OTHER
};

struct CryptoInfo {
  CryptoInfo() : tag(0) {}

  int tag;
  std::string cipher_suite;
  std::string key_params;
  //int ssrc;
  mediaType media_type;

};

struct CandidateInfo{
	CandidateInfo() : tag(0){}
	bool isBundle;
	int tag;
	unsigned int priority;
	unsigned int compid;
	std::string foundation;
	std::string host_address;
	std::string relay_address;
	int host_port;
	int relay_port;
	std::string net_prot;
	hostType type;
	std::string trans_prot;
	std::string username;
	std::string passwd;
	mediaType media_type;
};

class SDPInfo {
public:
	SDPInfo();
	virtual ~SDPInfo();
	bool initWithSDP(const std::string &sdp);
	void addCandidate (const CandidateInfo &info);
	void addCrypto (const CryptoInfo &info);
	std::vector<CandidateInfo> &getCandidateInfos();
	std::vector<CryptoInfo> &getCryptoInfos();
	std::string getSDP();
	int audio_ssrc, video_ssrc;


private:
	bool processSDP(const std::string &sdp);
	bool processCandidate (char** pieces, int size, mediaType media_type);
	std::vector<CandidateInfo> cand_vector;
	std::vector<CryptoInfo> crypto_vector;
	std::string ice_username;
	std::string ice_passwd;

};

#endif /* SDPPROCESSOR_H_ */