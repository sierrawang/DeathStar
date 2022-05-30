/**
 * Autogenerated by Thrift Compiler (0.16.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "MediaService.h"

namespace social_network {


MediaService_ComposeMedia_args::~MediaService_ComposeMedia_args() noexcept {
}


uint32_t MediaService_ComposeMedia_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->media_types.clear();
            uint32_t _size484;
            ::apache::thrift::protocol::TType _etype487;
            xfer += iprot->readListBegin(_etype487, _size484);
            this->media_types.resize(_size484);
            uint32_t _i488;
            for (_i488 = 0; _i488 < _size484; ++_i488)
            {
              xfer += iprot->readString(this->media_types[_i488]);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.media_types = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->media_ids.clear();
            uint32_t _size489;
            ::apache::thrift::protocol::TType _etype492;
            xfer += iprot->readListBegin(_etype492, _size489);
            this->media_ids.resize(_size489);
            uint32_t _i493;
            for (_i493 = 0; _i493 < _size489; ++_i493)
            {
              xfer += iprot->readI64(this->media_ids[_i493]);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.media_ids = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_MAP) {
          {
            this->carrier.clear();
            uint32_t _size494;
            ::apache::thrift::protocol::TType _ktype495;
            ::apache::thrift::protocol::TType _vtype496;
            xfer += iprot->readMapBegin(_ktype495, _vtype496, _size494);
            uint32_t _i498;
            for (_i498 = 0; _i498 < _size494; ++_i498)
            {
              std::string _key499;
              xfer += iprot->readString(_key499);
              std::string& _val500 = this->carrier[_key499];
              xfer += iprot->readString(_val500);
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

uint32_t MediaService_ComposeMedia_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("MediaService_ComposeMedia_args");

  xfer += oprot->writeFieldBegin("req_id", ::apache::thrift::protocol::T_I64, 1);
  xfer += oprot->writeI64(this->req_id);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("media_types", ::apache::thrift::protocol::T_LIST, 2);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRING, static_cast<uint32_t>(this->media_types.size()));
    std::vector<std::string> ::const_iterator _iter501;
    for (_iter501 = this->media_types.begin(); _iter501 != this->media_types.end(); ++_iter501)
    {
      xfer += oprot->writeString((*_iter501));
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("media_ids", ::apache::thrift::protocol::T_LIST, 3);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_I64, static_cast<uint32_t>(this->media_ids.size()));
    std::vector<int64_t> ::const_iterator _iter502;
    for (_iter502 = this->media_ids.begin(); _iter502 != this->media_ids.end(); ++_iter502)
    {
      xfer += oprot->writeI64((*_iter502));
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("carrier", ::apache::thrift::protocol::T_MAP, 4);
  {
    xfer += oprot->writeMapBegin(::apache::thrift::protocol::T_STRING, ::apache::thrift::protocol::T_STRING, static_cast<uint32_t>(this->carrier.size()));
    std::map<std::string, std::string> ::const_iterator _iter503;
    for (_iter503 = this->carrier.begin(); _iter503 != this->carrier.end(); ++_iter503)
    {
      xfer += oprot->writeString(_iter503->first);
      xfer += oprot->writeString(_iter503->second);
    }
    xfer += oprot->writeMapEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


MediaService_ComposeMedia_pargs::~MediaService_ComposeMedia_pargs() noexcept {
}


uint32_t MediaService_ComposeMedia_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("MediaService_ComposeMedia_pargs");

  xfer += oprot->writeFieldBegin("req_id", ::apache::thrift::protocol::T_I64, 1);
  xfer += oprot->writeI64((*(this->req_id)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("media_types", ::apache::thrift::protocol::T_LIST, 2);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRING, static_cast<uint32_t>((*(this->media_types)).size()));
    std::vector<std::string> ::const_iterator _iter504;
    for (_iter504 = (*(this->media_types)).begin(); _iter504 != (*(this->media_types)).end(); ++_iter504)
    {
      xfer += oprot->writeString((*_iter504));
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("media_ids", ::apache::thrift::protocol::T_LIST, 3);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_I64, static_cast<uint32_t>((*(this->media_ids)).size()));
    std::vector<int64_t> ::const_iterator _iter505;
    for (_iter505 = (*(this->media_ids)).begin(); _iter505 != (*(this->media_ids)).end(); ++_iter505)
    {
      xfer += oprot->writeI64((*_iter505));
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("carrier", ::apache::thrift::protocol::T_MAP, 4);
  {
    xfer += oprot->writeMapBegin(::apache::thrift::protocol::T_STRING, ::apache::thrift::protocol::T_STRING, static_cast<uint32_t>((*(this->carrier)).size()));
    std::map<std::string, std::string> ::const_iterator _iter506;
    for (_iter506 = (*(this->carrier)).begin(); _iter506 != (*(this->carrier)).end(); ++_iter506)
    {
      xfer += oprot->writeString(_iter506->first);
      xfer += oprot->writeString(_iter506->second);
    }
    xfer += oprot->writeMapEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


MediaService_ComposeMedia_result::~MediaService_ComposeMedia_result() noexcept {
}


uint32_t MediaService_ComposeMedia_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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
            uint32_t _size507;
            ::apache::thrift::protocol::TType _etype510;
            xfer += iprot->readListBegin(_etype510, _size507);
            this->success.resize(_size507);
            uint32_t _i511;
            for (_i511 = 0; _i511 < _size507; ++_i511)
            {
              xfer += this->success[_i511].read(iprot);
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

uint32_t MediaService_ComposeMedia_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("MediaService_ComposeMedia_result");

  if (this->__isset.success) {
    xfer += oprot->writeFieldBegin("success", ::apache::thrift::protocol::T_LIST, 0);
    {
      xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->success.size()));
      std::vector<Media> ::const_iterator _iter512;
      for (_iter512 = this->success.begin(); _iter512 != this->success.end(); ++_iter512)
      {
        xfer += (*_iter512).write(oprot);
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


MediaService_ComposeMedia_presult::~MediaService_ComposeMedia_presult() noexcept {
}


uint32_t MediaService_ComposeMedia_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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
            uint32_t _size513;
            ::apache::thrift::protocol::TType _etype516;
            xfer += iprot->readListBegin(_etype516, _size513);
            (*(this->success)).resize(_size513);
            uint32_t _i517;
            for (_i517 = 0; _i517 < _size513; ++_i517)
            {
              xfer += (*(this->success))[_i517].read(iprot);
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

void MediaServiceClient::ComposeMedia(std::vector<Media> & _return, const int64_t req_id, const std::vector<std::string> & media_types, const std::vector<int64_t> & media_ids, const std::map<std::string, std::string> & carrier)
{
  send_ComposeMedia(req_id, media_types, media_ids, carrier);
  recv_ComposeMedia(_return);
}

void MediaServiceClient::send_ComposeMedia(const int64_t req_id, const std::vector<std::string> & media_types, const std::vector<int64_t> & media_ids, const std::map<std::string, std::string> & carrier)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("ComposeMedia", ::apache::thrift::protocol::T_CALL, cseqid);

  MediaService_ComposeMedia_pargs args;
  args.req_id = &req_id;
  args.media_types = &media_types;
  args.media_ids = &media_ids;
  args.carrier = &carrier;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

void MediaServiceClient::recv_ComposeMedia(std::vector<Media> & _return)
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
  if (fname.compare("ComposeMedia") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
  MediaService_ComposeMedia_presult result;
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
  throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "ComposeMedia failed: unknown result");
}

bool MediaServiceProcessor::dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext) {
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

void MediaServiceProcessor::process_ComposeMedia(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = nullptr;
  if (this->eventHandler_.get() != nullptr) {
    ctx = this->eventHandler_->getContext("MediaService.ComposeMedia", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "MediaService.ComposeMedia");

  if (this->eventHandler_.get() != nullptr) {
    this->eventHandler_->preRead(ctx, "MediaService.ComposeMedia");
  }

  MediaService_ComposeMedia_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != nullptr) {
    this->eventHandler_->postRead(ctx, "MediaService.ComposeMedia", bytes);
  }

  MediaService_ComposeMedia_result result;
  try {
    iface_->ComposeMedia(result.success, args.req_id, args.media_types, args.media_ids, args.carrier);
    result.__isset.success = true;
  } catch (ServiceException &se) {
    result.se = std::move(se);
    result.__isset.se = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != nullptr) {
      this->eventHandler_->handlerError(ctx, "MediaService.ComposeMedia");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("ComposeMedia", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != nullptr) {
    this->eventHandler_->preWrite(ctx, "MediaService.ComposeMedia");
  }

  oprot->writeMessageBegin("ComposeMedia", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != nullptr) {
    this->eventHandler_->postWrite(ctx, "MediaService.ComposeMedia", bytes);
  }
}

::std::shared_ptr< ::apache::thrift::TProcessor > MediaServiceProcessorFactory::getProcessor(const ::apache::thrift::TConnectionInfo& connInfo) {
  ::apache::thrift::ReleaseHandler< MediaServiceIfFactory > cleanup(handlerFactory_);
  ::std::shared_ptr< MediaServiceIf > handler(handlerFactory_->getHandler(connInfo), cleanup);
  ::std::shared_ptr< ::apache::thrift::TProcessor > processor(new MediaServiceProcessor(handler));
  return processor;
}

void MediaServiceConcurrentClient::ComposeMedia(std::vector<Media> & _return, const int64_t req_id, const std::vector<std::string> & media_types, const std::vector<int64_t> & media_ids, const std::map<std::string, std::string> & carrier)
{
  int32_t seqid = send_ComposeMedia(req_id, media_types, media_ids, carrier);
  recv_ComposeMedia(_return, seqid);
}

int32_t MediaServiceConcurrentClient::send_ComposeMedia(const int64_t req_id, const std::vector<std::string> & media_types, const std::vector<int64_t> & media_ids, const std::map<std::string, std::string> & carrier)
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("ComposeMedia", ::apache::thrift::protocol::T_CALL, cseqid);

  MediaService_ComposeMedia_pargs args;
  args.req_id = &req_id;
  args.media_types = &media_types;
  args.media_ids = &media_ids;
  args.carrier = &carrier;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

void MediaServiceConcurrentClient::recv_ComposeMedia(std::vector<Media> & _return, const int32_t seqid)
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
      if (fname.compare("ComposeMedia") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();

        // in a bad state, don't commit
        using ::apache::thrift::protocol::TProtocolException;
        throw TProtocolException(TProtocolException::INVALID_DATA);
      }
      MediaService_ComposeMedia_presult result;
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
      throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "ComposeMedia failed: unknown result");
    }
    // seqid != rseqid
    this->sync_->updatePending(fname, mtype, rseqid);

    // this will temporarily unlock the readMutex, and let other clients get work done
    this->sync_->waitForWork(seqid);
  } // end while(true)
}

} // namespace

