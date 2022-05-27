/**
 * Autogenerated by Thrift Compiler (0.16.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef UserStorageService_H
#define UserStorageService_H

#include <thrift/TDispatchProcessor.h>
#include <thrift/async/TConcurrentClientSyncInfo.h>
#include <memory>
#include "social_network_types.h"

namespace social_network {

#ifdef _MSC_VER
  #pragma warning( push )
  #pragma warning (disable : 4250 ) //inheriting methods via dominance 
#endif

class UserStorageServiceIf {
 public:
  virtual ~UserStorageServiceIf() {}
  virtual void WriteUser(const User& user) = 0;
  virtual void ReadUser(User& _return, const int64_t user_id) = 0;
  virtual void FindUser(User& _return, const std::string& username) = 0;
};

class UserStorageServiceIfFactory {
 public:
  typedef UserStorageServiceIf Handler;

  virtual ~UserStorageServiceIfFactory() {}

  virtual UserStorageServiceIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(UserStorageServiceIf* /* handler */) = 0;
  };

class UserStorageServiceIfSingletonFactory : virtual public UserStorageServiceIfFactory {
 public:
  UserStorageServiceIfSingletonFactory(const ::std::shared_ptr<UserStorageServiceIf>& iface) : iface_(iface) {}
  virtual ~UserStorageServiceIfSingletonFactory() {}

  virtual UserStorageServiceIf* getHandler(const ::apache::thrift::TConnectionInfo&) override {
    return iface_.get();
  }
  virtual void releaseHandler(UserStorageServiceIf* /* handler */) override {}

 protected:
  ::std::shared_ptr<UserStorageServiceIf> iface_;
};

class UserStorageServiceNull : virtual public UserStorageServiceIf {
 public:
  virtual ~UserStorageServiceNull() {}
  void WriteUser(const User& /* user */) override {
    return;
  }
  void ReadUser(User& /* _return */, const int64_t /* user_id */) override {
    return;
  }
  void FindUser(User& /* _return */, const std::string& /* username */) override {
    return;
  }
};

typedef struct _UserStorageService_WriteUser_args__isset {
  _UserStorageService_WriteUser_args__isset() : user(false) {}
  bool user :1;
} _UserStorageService_WriteUser_args__isset;

class UserStorageService_WriteUser_args {
 public:

  UserStorageService_WriteUser_args(const UserStorageService_WriteUser_args&);
  UserStorageService_WriteUser_args& operator=(const UserStorageService_WriteUser_args&);
  UserStorageService_WriteUser_args() noexcept {
  }

  virtual ~UserStorageService_WriteUser_args() noexcept;
  User user;

  _UserStorageService_WriteUser_args__isset __isset;

  void __set_user(const User& val);

  bool operator == (const UserStorageService_WriteUser_args & rhs) const
  {
    if (!(user == rhs.user))
      return false;
    return true;
  }
  bool operator != (const UserStorageService_WriteUser_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const UserStorageService_WriteUser_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class UserStorageService_WriteUser_pargs {
 public:


  virtual ~UserStorageService_WriteUser_pargs() noexcept;
  const User* user;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _UserStorageService_WriteUser_result__isset {
  _UserStorageService_WriteUser_result__isset() : se(false) {}
  bool se :1;
} _UserStorageService_WriteUser_result__isset;

class UserStorageService_WriteUser_result {
 public:

  UserStorageService_WriteUser_result(const UserStorageService_WriteUser_result&);
  UserStorageService_WriteUser_result& operator=(const UserStorageService_WriteUser_result&);
  UserStorageService_WriteUser_result() noexcept {
  }

  virtual ~UserStorageService_WriteUser_result() noexcept;
  ServiceException se;

  _UserStorageService_WriteUser_result__isset __isset;

  void __set_se(const ServiceException& val);

  bool operator == (const UserStorageService_WriteUser_result & rhs) const
  {
    if (!(se == rhs.se))
      return false;
    return true;
  }
  bool operator != (const UserStorageService_WriteUser_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const UserStorageService_WriteUser_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _UserStorageService_WriteUser_presult__isset {
  _UserStorageService_WriteUser_presult__isset() : se(false) {}
  bool se :1;
} _UserStorageService_WriteUser_presult__isset;

class UserStorageService_WriteUser_presult {
 public:


  virtual ~UserStorageService_WriteUser_presult() noexcept;
  ServiceException se;

  _UserStorageService_WriteUser_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _UserStorageService_ReadUser_args__isset {
  _UserStorageService_ReadUser_args__isset() : user_id(false) {}
  bool user_id :1;
} _UserStorageService_ReadUser_args__isset;

class UserStorageService_ReadUser_args {
 public:

  UserStorageService_ReadUser_args(const UserStorageService_ReadUser_args&) noexcept;
  UserStorageService_ReadUser_args& operator=(const UserStorageService_ReadUser_args&) noexcept;
  UserStorageService_ReadUser_args() noexcept
                                   : user_id(0) {
  }

  virtual ~UserStorageService_ReadUser_args() noexcept;
  int64_t user_id;

  _UserStorageService_ReadUser_args__isset __isset;

  void __set_user_id(const int64_t val);

  bool operator == (const UserStorageService_ReadUser_args & rhs) const
  {
    if (!(user_id == rhs.user_id))
      return false;
    return true;
  }
  bool operator != (const UserStorageService_ReadUser_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const UserStorageService_ReadUser_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class UserStorageService_ReadUser_pargs {
 public:


  virtual ~UserStorageService_ReadUser_pargs() noexcept;
  const int64_t* user_id;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _UserStorageService_ReadUser_result__isset {
  _UserStorageService_ReadUser_result__isset() : success(false), se(false) {}
  bool success :1;
  bool se :1;
} _UserStorageService_ReadUser_result__isset;

class UserStorageService_ReadUser_result {
 public:

  UserStorageService_ReadUser_result(const UserStorageService_ReadUser_result&);
  UserStorageService_ReadUser_result& operator=(const UserStorageService_ReadUser_result&);
  UserStorageService_ReadUser_result() noexcept {
  }

  virtual ~UserStorageService_ReadUser_result() noexcept;
  User success;
  ServiceException se;

  _UserStorageService_ReadUser_result__isset __isset;

  void __set_success(const User& val);

  void __set_se(const ServiceException& val);

  bool operator == (const UserStorageService_ReadUser_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(se == rhs.se))
      return false;
    return true;
  }
  bool operator != (const UserStorageService_ReadUser_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const UserStorageService_ReadUser_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _UserStorageService_ReadUser_presult__isset {
  _UserStorageService_ReadUser_presult__isset() : success(false), se(false) {}
  bool success :1;
  bool se :1;
} _UserStorageService_ReadUser_presult__isset;

class UserStorageService_ReadUser_presult {
 public:


  virtual ~UserStorageService_ReadUser_presult() noexcept;
  User* success;
  ServiceException se;

  _UserStorageService_ReadUser_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _UserStorageService_FindUser_args__isset {
  _UserStorageService_FindUser_args__isset() : username(false) {}
  bool username :1;
} _UserStorageService_FindUser_args__isset;

class UserStorageService_FindUser_args {
 public:

  UserStorageService_FindUser_args(const UserStorageService_FindUser_args&);
  UserStorageService_FindUser_args& operator=(const UserStorageService_FindUser_args&);
  UserStorageService_FindUser_args() noexcept
                                   : username() {
  }

  virtual ~UserStorageService_FindUser_args() noexcept;
  std::string username;

  _UserStorageService_FindUser_args__isset __isset;

  void __set_username(const std::string& val);

  bool operator == (const UserStorageService_FindUser_args & rhs) const
  {
    if (!(username == rhs.username))
      return false;
    return true;
  }
  bool operator != (const UserStorageService_FindUser_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const UserStorageService_FindUser_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class UserStorageService_FindUser_pargs {
 public:


  virtual ~UserStorageService_FindUser_pargs() noexcept;
  const std::string* username;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _UserStorageService_FindUser_result__isset {
  _UserStorageService_FindUser_result__isset() : success(false), se(false) {}
  bool success :1;
  bool se :1;
} _UserStorageService_FindUser_result__isset;

class UserStorageService_FindUser_result {
 public:

  UserStorageService_FindUser_result(const UserStorageService_FindUser_result&);
  UserStorageService_FindUser_result& operator=(const UserStorageService_FindUser_result&);
  UserStorageService_FindUser_result() noexcept {
  }

  virtual ~UserStorageService_FindUser_result() noexcept;
  User success;
  ServiceException se;

  _UserStorageService_FindUser_result__isset __isset;

  void __set_success(const User& val);

  void __set_se(const ServiceException& val);

  bool operator == (const UserStorageService_FindUser_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(se == rhs.se))
      return false;
    return true;
  }
  bool operator != (const UserStorageService_FindUser_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const UserStorageService_FindUser_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _UserStorageService_FindUser_presult__isset {
  _UserStorageService_FindUser_presult__isset() : success(false), se(false) {}
  bool success :1;
  bool se :1;
} _UserStorageService_FindUser_presult__isset;

class UserStorageService_FindUser_presult {
 public:


  virtual ~UserStorageService_FindUser_presult() noexcept;
  User* success;
  ServiceException se;

  _UserStorageService_FindUser_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class UserStorageServiceClient : virtual public UserStorageServiceIf {
 public:
  UserStorageServiceClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  UserStorageServiceClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void WriteUser(const User& user) override;
  void send_WriteUser(const User& user);
  void recv_WriteUser();
  void ReadUser(User& _return, const int64_t user_id) override;
  void send_ReadUser(const int64_t user_id);
  void recv_ReadUser(User& _return);
  void FindUser(User& _return, const std::string& username) override;
  void send_FindUser(const std::string& username);
  void recv_FindUser(User& _return);
 protected:
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class UserStorageServiceProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  ::std::shared_ptr<UserStorageServiceIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext) override;
 private:
  typedef  void (UserStorageServiceProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_WriteUser(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_ReadUser(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_FindUser(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  UserStorageServiceProcessor(::std::shared_ptr<UserStorageServiceIf> iface) :
    iface_(iface) {
    processMap_["WriteUser"] = &UserStorageServiceProcessor::process_WriteUser;
    processMap_["ReadUser"] = &UserStorageServiceProcessor::process_ReadUser;
    processMap_["FindUser"] = &UserStorageServiceProcessor::process_FindUser;
  }

  virtual ~UserStorageServiceProcessor() {}
};

class UserStorageServiceProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  UserStorageServiceProcessorFactory(const ::std::shared_ptr< UserStorageServiceIfFactory >& handlerFactory) noexcept :
      handlerFactory_(handlerFactory) {}

  ::std::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo) override;

 protected:
  ::std::shared_ptr< UserStorageServiceIfFactory > handlerFactory_;
};

class UserStorageServiceMultiface : virtual public UserStorageServiceIf {
 public:
  UserStorageServiceMultiface(std::vector<std::shared_ptr<UserStorageServiceIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~UserStorageServiceMultiface() {}
 protected:
  std::vector<std::shared_ptr<UserStorageServiceIf> > ifaces_;
  UserStorageServiceMultiface() {}
  void add(::std::shared_ptr<UserStorageServiceIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  void WriteUser(const User& user) override {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->WriteUser(user);
    }
    ifaces_[i]->WriteUser(user);
  }

  void ReadUser(User& _return, const int64_t user_id) override {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->ReadUser(_return, user_id);
    }
    ifaces_[i]->ReadUser(_return, user_id);
    return;
  }

  void FindUser(User& _return, const std::string& username) override {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->FindUser(_return, username);
    }
    ifaces_[i]->FindUser(_return, username);
    return;
  }

};

// The 'concurrent' client is a thread safe client that correctly handles
// out of order responses.  It is slower than the regular client, so should
// only be used when you need to share a connection among multiple threads
class UserStorageServiceConcurrentClient : virtual public UserStorageServiceIf {
 public:
  UserStorageServiceConcurrentClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot, std::shared_ptr<::apache::thrift::async::TConcurrentClientSyncInfo> sync) : sync_(sync)
{
    setProtocol(prot);
  }
  UserStorageServiceConcurrentClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot, std::shared_ptr<::apache::thrift::async::TConcurrentClientSyncInfo> sync) : sync_(sync)
{
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void WriteUser(const User& user) override;
  int32_t send_WriteUser(const User& user);
  void recv_WriteUser(const int32_t seqid);
  void ReadUser(User& _return, const int64_t user_id) override;
  int32_t send_ReadUser(const int64_t user_id);
  void recv_ReadUser(User& _return, const int32_t seqid);
  void FindUser(User& _return, const std::string& username) override;
  int32_t send_FindUser(const std::string& username);
  void recv_FindUser(User& _return, const int32_t seqid);
 protected:
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
  std::shared_ptr<::apache::thrift::async::TConcurrentClientSyncInfo> sync_;
};

#ifdef _MSC_VER
  #pragma warning( pop )
#endif

} // namespace

#endif
