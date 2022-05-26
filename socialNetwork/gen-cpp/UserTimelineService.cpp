/**
 * Autogenerated by Thrift Compiler (0.16.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "UserTimelineService.h"

namespace social_network {


UserTimelineService_WriteUserTimeline_args::~UserTimelineService_WriteUserTimeline_args() noexcept {
}


uint32_t UserTimelineService_WriteUserTimeline_args::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->req_id);
          this->__isset.req_id = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->post_id);
          this->__isset.post_id = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->user_id);
          this->__isset.user_id = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->timestamp);
          this->__isset.timestamp = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_MAP) {
          {
            this->carrier.clear();
            uint32_t _size226;
            ::apache::thrift::protocol::TType _ktype227;
            ::apache::thrift::protocol::TType _vtype228;
            xfer += iprot->readMapBegin(_ktype227, _vtype228, _size226);
            uint32_t _i230;
            for (_i230 = 0; _i230 < _size226; ++_i230)
            {
              std::string _key231;
              xfer += iprot->readString(_key231);
              std::string& _val232 = this->carrier[_key231];
              xfer += iprot->readString(_val232);
            }
            xfer += iprot->readMapEnd();
          }
          this->__isset.carrier = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t UserTimelineService_WriteUserTimeline_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("UserTimelineService_WriteUserTimeline_args");

  xfer += oprot->writeFieldBegin("req_id", ::apache::thrift::protocol::T_I64, 1);
  xfer += oprot->writeI64(this->req_id);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("post_id", ::apache::thrift::protocol::T_I64, 2);
  xfer += oprot->writeI64(this->post_id);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("user_id", ::apache::thrift::protocol::T_I64, 3);
  xfer += oprot->writeI64(this->user_id);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("timestamp", ::apache::thrift::protocol::T_I64, 4);
  xfer += oprot->writeI64(this->timestamp);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("carrier", ::apache::thrift::protocol::T_MAP, 5);
  {
    xfer += oprot->writeMapBegin(::apache::thrift::protocol::T_STRING, ::apache::thrift::protocol::T_STRING, static_cast<uint32_t>(this->carrier.size()));
    std::map<std::string, std::string> ::const_iterator _iter233;
    for (_iter233 = this->carrier.begin(); _iter233 != this->carrier.end(); ++_iter233)
    {
      xfer += oprot->writeString(_iter233->first);
      xfer += oprot->writeString(_iter233->second);
    }
    xfer += oprot->writeMapEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


UserTimelineService_WriteUserTimeline_pargs::~UserTimelineService_WriteUserTimeline_pargs() noexcept {
}


uint32_t UserTimelineService_WriteUserTimeline_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("UserTimelineService_WriteUserTimeline_pargs");

  xfer += oprot->writeFieldBegin("req_id", ::apache::thrift::protocol::T_I64, 1);
  xfer += oprot->writeI64((*(this->req_id)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("post_id", ::apache::thrift::protocol::T_I64, 2);
  xfer += oprot->writeI64((*(this->post_id)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("user_id", ::apache::thrift::protocol::T_I64, 3);
  xfer += oprot->writeI64((*(this->user_id)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("timestamp", ::apache::thrift::protocol::T_I64, 4);
  xfer += oprot->writeI64((*(this->timestamp)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("carrier", ::apache::thrift::protocol::T_MAP, 5);
  {
    xfer += oprot->writeMapBegin(::apache::thrift::protocol::T_STRING, ::apache::thrift::protocol::T_STRING, static_cast<uint32_t>((*(this->carrier)).size()));
    std::map<std::string, std::string> ::const_iterator _iter234;
    for (_iter234 = (*(this->carrier)).begin(); _iter234 != (*(this->carrier)).end(); ++_iter234)
    {
      xfer += oprot->writeString(_iter234->first);
      xfer += oprot->writeString(_iter234->second);
    }
    xfer += oprot->writeMapEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


UserTimelineService_WriteUserTimeline_result::~UserTimelineService_WriteUserTimeline_result() noexcept {
}


uint32_t UserTimelineService_WriteUserTimeline_result::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->se.read(iprot);
          this->__isset.se = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t UserTimelineService_WriteUserTimeline_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("UserTimelineService_WriteUserTimeline_result");

  if (this->__isset.se) {
    xfer += oprot->writeFieldBegin("se", ::apache::thrift::protocol::T_STRUCT, 1);
    xfer += this->se.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


UserTimelineService_WriteUserTimeline_presult::~UserTimelineService_WriteUserTimeline_presult() noexcept {
}


uint32_t UserTimelineService_WriteUserTimeline_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->se.read(iprot);
          this->__isset.se = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}


UserTimelineService_ReadUserTimeline_args::~UserTimelineService_ReadUserTimeline_args() noexcept {
}


uint32_t UserTimelineService_ReadUserTimeline_args::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->req_id);
          this->__isset.req_id = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->user_id);
          this->__isset.user_id = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->start);
          this->__isset.start = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->stop);
          this->__isset.stop = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_MAP) {
          {
            this->carrier.clear();
            uint32_t _size235;
            ::apache::thrift::protocol::TType _ktype236;
            ::apache::thrift::protocol::TType _vtype237;
            xfer += iprot->readMapBegin(_ktype236, _vtype237, _size235);
            uint32_t _i239;
            for (_i239 = 0; _i239 < _size235; ++_i239)
            {
              std::string _key240;
              xfer += iprot->readString(_key240);
              std::string& _val241 = this->carrier[_key240];
              xfer += iprot->readString(_val241);
            }
            xfer += iprot->readMapEnd();
          }
          this->__isset.carrier = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t UserTimelineService_ReadUserTimeline_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("UserTimelineService_ReadUserTimeline_args");

  xfer += oprot->writeFieldBegin("req_id", ::apache::thrift::protocol::T_I64, 1);
  xfer += oprot->writeI64(this->req_id);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("user_id", ::apache::thrift::protocol::T_I64, 2);
  xfer += oprot->writeI64(this->user_id);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("start", ::apache::thrift::protocol::T_I32, 3);
  xfer += oprot->writeI32(this->start);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("stop", ::apache::thrift::protocol::T_I32, 4);
  xfer += oprot->writeI32(this->stop);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("carrier", ::apache::thrift::protocol::T_MAP, 5);
  {
    xfer += oprot->writeMapBegin(::apache::thrift::protocol::T_STRING, ::apache::thrift::protocol::T_STRING, static_cast<uint32_t>(this->carrier.size()));
    std::map<std::string, std::string> ::const_iterator _iter242;
    for (_iter242 = this->carrier.begin(); _iter242 != this->carrier.end(); ++_iter242)
    {
      xfer += oprot->writeString(_iter242->first);
      xfer += oprot->writeString(_iter242->second);
    }
    xfer += oprot->writeMapEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


UserTimelineService_ReadUserTimeline_pargs::~UserTimelineService_ReadUserTimeline_pargs() noexcept {
}


uint32_t UserTimelineService_ReadUserTimeline_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("UserTimelineService_ReadUserTimeline_pargs");

  xfer += oprot->writeFieldBegin("req_id", ::apache::thrift::protocol::T_I64, 1);
  xfer += oprot->writeI64((*(this->req_id)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("user_id", ::apache::thrift::protocol::T_I64, 2);
  xfer += oprot->writeI64((*(this->user_id)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("start", ::apache::thrift::protocol::T_I32, 3);
  xfer += oprot->writeI32((*(this->start)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("stop", ::apache::thrift::protocol::T_I32, 4);
  xfer += oprot->writeI32((*(this->stop)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("carrier", ::apache::thrift::protocol::T_MAP, 5);
  {
    xfer += oprot->writeMapBegin(::apache::thrift::protocol::T_STRING, ::apache::thrift::protocol::T_STRING, static_cast<uint32_t>((*(this->carrier)).size()));
    std::map<std::string, std::string> ::const_iterator _iter243;
    for (_iter243 = (*(this->carrier)).begin(); _iter243 != (*(this->carrier)).end(); ++_iter243)
    {
      xfer += oprot->writeString(_iter243->first);
      xfer += oprot->writeString(_iter243->second);
    }
    xfer += oprot->writeMapEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


UserTimelineService_ReadUserTimeline_result::~UserTimelineService_ReadUserTimeline_result() noexcept {
}


uint32_t UserTimelineService_ReadUserTimeline_result::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 0:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->success.clear();
            uint32_t _size244;
            ::apache::thrift::protocol::TType _etype247;
            xfer += iprot->readListBegin(_etype247, _size244);
            this->success.resize(_size244);
            uint32_t _i248;
            for (_i248 = 0; _i248 < _size244; ++_i248)
            {
              xfer += this->success[_i248].read(iprot);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.success = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->se.read(iprot);
          this->__isset.se = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t UserTimelineService_ReadUserTimeline_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("UserTimelineService_ReadUserTimeline_result");

  if (this->__isset.success) {
    xfer += oprot->writeFieldBegin("success", ::apache::thrift::protocol::T_LIST, 0);
    {
      xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->success.size()));
      std::vector<Post> ::const_iterator _iter249;
      for (_iter249 = this->success.begin(); _iter249 != this->success.end(); ++_iter249)
      {
        xfer += (*_iter249).write(oprot);
      }
      xfer += oprot->writeListEnd();
    }
    xfer += oprot->writeFieldEnd();
  } else if (this->__isset.se) {
    xfer += oprot->writeFieldBegin("se", ::apache::thrift::protocol::T_STRUCT, 1);
    xfer += this->se.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


UserTimelineService_ReadUserTimeline_presult::~UserTimelineService_ReadUserTimeline_presult() noexcept {
}


uint32_t UserTimelineService_ReadUserTimeline_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 0:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            (*(this->success)).clear();
            uint32_t _size250;
            ::apache::thrift::protocol::TType _etype253;
            xfer += iprot->readListBegin(_etype253, _size250);
            (*(this->success)).resize(_size250);
            uint32_t _i254;
            for (_i254 = 0; _i254 < _size250; ++_i254)
            {
              xfer += (*(this->success))[_i254].read(iprot);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.success = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->se.read(iprot);
          this->__isset.se = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

void UserTimelineServiceClient::WriteUserTimeline(const int64_t req_id, const int64_t post_id, const int64_t user_id, const int64_t timestamp, const std::map<std::string, std::string> & carrier)
{
  send_WriteUserTimeline(req_id, post_id, user_id, timestamp, carrier);
  recv_WriteUserTimeline();
}

void UserTimelineServiceClient::send_WriteUserTimeline(const int64_t req_id, const int64_t post_id, const int64_t user_id, const int64_t timestamp, const std::map<std::string, std::string> & carrier)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("WriteUserTimeline", ::apache::thrift::protocol::T_CALL, cseqid);

  UserTimelineService_WriteUserTimeline_pargs args;
  args.req_id = &req_id;
  args.post_id = &post_id;
  args.user_id = &user_id;
  args.timestamp = &timestamp;
  args.carrier = &carrier;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

void UserTimelineServiceClient::recv_WriteUserTimeline()
{

  int32_t rseqid = 0;
  std::string fname;
  ::apache::thrift::protocol::TMessageType mtype;

  iprot_->readMessageBegin(fname, mtype, rseqid);
  if (mtype == ::apache::thrift::protocol::T_EXCEPTION) {
    ::apache::thrift::TApplicationException x;
    x.read(iprot_);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
    throw x;
  }
  if (mtype != ::apache::thrift::protocol::T_REPLY) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
  if (fname.compare("WriteUserTimeline") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
  UserTimelineService_WriteUserTimeline_presult result;
  result.read(iprot_);
  iprot_->readMessageEnd();
  iprot_->getTransport()->readEnd();

  if (result.__isset.se) {
    throw result.se;
  }
  return;
}

void UserTimelineServiceClient::ReadUserTimeline(std::vector<Post> & _return, const int64_t req_id, const int64_t user_id, const int32_t start, const int32_t stop, const std::map<std::string, std::string> & carrier)
{
  send_ReadUserTimeline(req_id, user_id, start, stop, carrier);
  recv_ReadUserTimeline(_return);
}

void UserTimelineServiceClient::send_ReadUserTimeline(const int64_t req_id, const int64_t user_id, const int32_t start, const int32_t stop, const std::map<std::string, std::string> & carrier)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("ReadUserTimeline", ::apache::thrift::protocol::T_CALL, cseqid);

  UserTimelineService_ReadUserTimeline_pargs args;
  args.req_id = &req_id;
  args.user_id = &user_id;
  args.start = &start;
  args.stop = &stop;
  args.carrier = &carrier;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

void UserTimelineServiceClient::recv_ReadUserTimeline(std::vector<Post> & _return)
{

  int32_t rseqid = 0;
  std::string fname;
  ::apache::thrift::protocol::TMessageType mtype;

  iprot_->readMessageBegin(fname, mtype, rseqid);
  if (mtype == ::apache::thrift::protocol::T_EXCEPTION) {
    ::apache::thrift::TApplicationException x;
    x.read(iprot_);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
    throw x;
  }
  if (mtype != ::apache::thrift::protocol::T_REPLY) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
  if (fname.compare("ReadUserTimeline") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
  UserTimelineService_ReadUserTimeline_presult result;
  result.success = &_return;
  result.read(iprot_);
  iprot_->readMessageEnd();
  iprot_->getTransport()->readEnd();

  if (result.__isset.success) {
    // _return pointer has now been filled
    return;
  }
  if (result.__isset.se) {
    throw result.se;
  }
  throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "ReadUserTimeline failed: unknown result");
}

bool UserTimelineServiceProcessor::dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext) {
  ProcessMap::iterator pfn;
  pfn = processMap_.find(fname);
  if (pfn == processMap_.end()) {
    iprot->skip(::apache::thrift::protocol::T_STRUCT);
    iprot->readMessageEnd();
    iprot->getTransport()->readEnd();
    ::apache::thrift::TApplicationException x(::apache::thrift::TApplicationException::UNKNOWN_METHOD, "Invalid method name: '"+fname+"'");
    oprot->writeMessageBegin(fname, ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return true;
  }
  (this->*(pfn->second))(seqid, iprot, oprot, callContext);
  return true;
}

void UserTimelineServiceProcessor::process_WriteUserTimeline(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = nullptr;
  if (this->eventHandler_.get() != nullptr) {
    ctx = this->eventHandler_->getContext("UserTimelineService.WriteUserTimeline", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "UserTimelineService.WriteUserTimeline");

  if (this->eventHandler_.get() != nullptr) {
    this->eventHandler_->preRead(ctx, "UserTimelineService.WriteUserTimeline");
  }

  UserTimelineService_WriteUserTimeline_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != nullptr) {
    this->eventHandler_->postRead(ctx, "UserTimelineService.WriteUserTimeline", bytes);
  }

  UserTimelineService_WriteUserTimeline_result result;
  try {
    iface_->WriteUserTimeline(args.req_id, args.post_id, args.user_id, args.timestamp, args.carrier);
  } catch (ServiceException &se) {
    result.se = std::move(se);
    result.__isset.se = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != nullptr) {
      this->eventHandler_->handlerError(ctx, "UserTimelineService.WriteUserTimeline");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("WriteUserTimeline", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != nullptr) {
    this->eventHandler_->preWrite(ctx, "UserTimelineService.WriteUserTimeline");
  }

  oprot->writeMessageBegin("WriteUserTimeline", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != nullptr) {
    this->eventHandler_->postWrite(ctx, "UserTimelineService.WriteUserTimeline", bytes);
  }
}

void UserTimelineServiceProcessor::process_ReadUserTimeline(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = nullptr;
  if (this->eventHandler_.get() != nullptr) {
    ctx = this->eventHandler_->getContext("UserTimelineService.ReadUserTimeline", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "UserTimelineService.ReadUserTimeline");

  if (this->eventHandler_.get() != nullptr) {
    this->eventHandler_->preRead(ctx, "UserTimelineService.ReadUserTimeline");
  }

  UserTimelineService_ReadUserTimeline_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != nullptr) {
    this->eventHandler_->postRead(ctx, "UserTimelineService.ReadUserTimeline", bytes);
  }

  UserTimelineService_ReadUserTimeline_result result;
  try {
    iface_->ReadUserTimeline(result.success, args.req_id, args.user_id, args.start, args.stop, args.carrier);
    result.__isset.success = true;
  } catch (ServiceException &se) {
    result.se = std::move(se);
    result.__isset.se = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != nullptr) {
      this->eventHandler_->handlerError(ctx, "UserTimelineService.ReadUserTimeline");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("ReadUserTimeline", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != nullptr) {
    this->eventHandler_->preWrite(ctx, "UserTimelineService.ReadUserTimeline");
  }

  oprot->writeMessageBegin("ReadUserTimeline", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != nullptr) {
    this->eventHandler_->postWrite(ctx, "UserTimelineService.ReadUserTimeline", bytes);
  }
}

::std::shared_ptr< ::apache::thrift::TProcessor > UserTimelineServiceProcessorFactory::getProcessor(const ::apache::thrift::TConnectionInfo& connInfo) {
  ::apache::thrift::ReleaseHandler< UserTimelineServiceIfFactory > cleanup(handlerFactory_);
  ::std::shared_ptr< UserTimelineServiceIf > handler(handlerFactory_->getHandler(connInfo), cleanup);
  ::std::shared_ptr< ::apache::thrift::TProcessor > processor(new UserTimelineServiceProcessor(handler));
  return processor;
}

void UserTimelineServiceConcurrentClient::WriteUserTimeline(const int64_t req_id, const int64_t post_id, const int64_t user_id, const int64_t timestamp, const std::map<std::string, std::string> & carrier)
{
  int32_t seqid = send_WriteUserTimeline(req_id, post_id, user_id, timestamp, carrier);
  recv_WriteUserTimeline(seqid);
}

int32_t UserTimelineServiceConcurrentClient::send_WriteUserTimeline(const int64_t req_id, const int64_t post_id, const int64_t user_id, const int64_t timestamp, const std::map<std::string, std::string> & carrier)
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("WriteUserTimeline", ::apache::thrift::protocol::T_CALL, cseqid);

  UserTimelineService_WriteUserTimeline_pargs args;
  args.req_id = &req_id;
  args.post_id = &post_id;
  args.user_id = &user_id;
  args.timestamp = &timestamp;
  args.carrier = &carrier;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

void UserTimelineServiceConcurrentClient::recv_WriteUserTimeline(const int32_t seqid)
{

  int32_t rseqid = 0;
  std::string fname;
  ::apache::thrift::protocol::TMessageType mtype;

  // the read mutex gets dropped and reacquired as part of waitForWork()
  // The destructor of this sentry wakes up other clients
  ::apache::thrift::async::TConcurrentRecvSentry sentry(this->sync_.get(), seqid);

  while(true) {
    if(!this->sync_->getPending(fname, mtype, rseqid)) {
      iprot_->readMessageBegin(fname, mtype, rseqid);
    }
    if(seqid == rseqid) {
      if (mtype == ::apache::thrift::protocol::T_EXCEPTION) {
        ::apache::thrift::TApplicationException x;
        x.read(iprot_);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();
        sentry.commit();
        throw x;
      }
      if (mtype != ::apache::thrift::protocol::T_REPLY) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();
      }
      if (fname.compare("WriteUserTimeline") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();

        // in a bad state, don't commit
        using ::apache::thrift::protocol::TProtocolException;
        throw TProtocolException(TProtocolException::INVALID_DATA);
      }
      UserTimelineService_WriteUserTimeline_presult result;
      result.read(iprot_);
      iprot_->readMessageEnd();
      iprot_->getTransport()->readEnd();

      if (result.__isset.se) {
        sentry.commit();
        throw result.se;
      }
      sentry.commit();
      return;
    }
    // seqid != rseqid
    this->sync_->updatePending(fname, mtype, rseqid);

    // this will temporarily unlock the readMutex, and let other clients get work done
    this->sync_->waitForWork(seqid);
  } // end while(true)
}

void UserTimelineServiceConcurrentClient::ReadUserTimeline(std::vector<Post> & _return, const int64_t req_id, const int64_t user_id, const int32_t start, const int32_t stop, const std::map<std::string, std::string> & carrier)
{
  int32_t seqid = send_ReadUserTimeline(req_id, user_id, start, stop, carrier);
  recv_ReadUserTimeline(_return, seqid);
}

int32_t UserTimelineServiceConcurrentClient::send_ReadUserTimeline(const int64_t req_id, const int64_t user_id, const int32_t start, const int32_t stop, const std::map<std::string, std::string> & carrier)
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("ReadUserTimeline", ::apache::thrift::protocol::T_CALL, cseqid);

  UserTimelineService_ReadUserTimeline_pargs args;
  args.req_id = &req_id;
  args.user_id = &user_id;
  args.start = &start;
  args.stop = &stop;
  args.carrier = &carrier;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

void UserTimelineServiceConcurrentClient::recv_ReadUserTimeline(std::vector<Post> & _return, const int32_t seqid)
{

  int32_t rseqid = 0;
  std::string fname;
  ::apache::thrift::protocol::TMessageType mtype;

  // the read mutex gets dropped and reacquired as part of waitForWork()
  // The destructor of this sentry wakes up other clients
  ::apache::thrift::async::TConcurrentRecvSentry sentry(this->sync_.get(), seqid);

  while(true) {
    if(!this->sync_->getPending(fname, mtype, rseqid)) {
      iprot_->readMessageBegin(fname, mtype, rseqid);
    }
    if(seqid == rseqid) {
      if (mtype == ::apache::thrift::protocol::T_EXCEPTION) {
        ::apache::thrift::TApplicationException x;
        x.read(iprot_);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();
        sentry.commit();
        throw x;
      }
      if (mtype != ::apache::thrift::protocol::T_REPLY) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();
      }
      if (fname.compare("ReadUserTimeline") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();

        // in a bad state, don't commit
        using ::apache::thrift::protocol::TProtocolException;
        throw TProtocolException(TProtocolException::INVALID_DATA);
      }
      UserTimelineService_ReadUserTimeline_presult result;
      result.success = &_return;
      result.read(iprot_);
      iprot_->readMessageEnd();
      iprot_->getTransport()->readEnd();

      if (result.__isset.success) {
        // _return pointer has now been filled
        sentry.commit();
        return;
      }
      if (result.__isset.se) {
        sentry.commit();
        throw result.se;
      }
      // in a bad state, don't commit
      throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "ReadUserTimeline failed: unknown result");
    }
    // seqid != rseqid
    this->sync_->updatePending(fname, mtype, rseqid);

    // this will temporarily unlock the readMutex, and let other clients get work done
    this->sync_->waitForWork(seqid);
  } // end while(true)
}

} // namespace

