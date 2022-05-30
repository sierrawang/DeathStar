#
# Autogenerated by Thrift Compiler (0.16.0)
#
# DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
#
#  options string: py
#

from thrift.Thrift import TType, TMessageType, TFrozenDict, TException, TApplicationException
from thrift.protocol.TProtocol import TProtocolException
from thrift.TRecursive import fix_spec

import sys
import logging
from .ttypes import *
from thrift.Thrift import TProcessor
from thrift.transport import TTransport
all_structs = []


class Iface(object):
    def ComposeUrls(self, req_id, urls, carrier):
        """
        Parameters:
         - req_id
         - urls
         - carrier

        """
        pass

    def GetExtendedUrls(self, req_id, shortened_urls, carrier):
        """
        Parameters:
         - req_id
         - shortened_urls
         - carrier

        """
        pass


class Client(Iface):
    def __init__(self, iprot, oprot=None):
        self._iprot = self._oprot = iprot
        if oprot is not None:
            self._oprot = oprot
        self._seqid = 0

    def ComposeUrls(self, req_id, urls, carrier):
        """
        Parameters:
         - req_id
         - urls
         - carrier

        """
        self.send_ComposeUrls(req_id, urls, carrier)
        return self.recv_ComposeUrls()

    def send_ComposeUrls(self, req_id, urls, carrier):
        self._oprot.writeMessageBegin('ComposeUrls', TMessageType.CALL, self._seqid)
        args = ComposeUrls_args()
        args.req_id = req_id
        args.urls = urls
        args.carrier = carrier
        args.write(self._oprot)
        self._oprot.writeMessageEnd()
        self._oprot.trans.flush()

    def recv_ComposeUrls(self):
        iprot = self._iprot
        (fname, mtype, rseqid) = iprot.readMessageBegin()
        if mtype == TMessageType.EXCEPTION:
            x = TApplicationException()
            x.read(iprot)
            iprot.readMessageEnd()
            raise x
        result = ComposeUrls_result()
        result.read(iprot)
        iprot.readMessageEnd()
        if result.success is not None:
            return result.success
        if result.se is not None:
            raise result.se
        raise TApplicationException(TApplicationException.MISSING_RESULT, "ComposeUrls failed: unknown result")

    def GetExtendedUrls(self, req_id, shortened_urls, carrier):
        """
        Parameters:
         - req_id
         - shortened_urls
         - carrier

        """
        self.send_GetExtendedUrls(req_id, shortened_urls, carrier)
        return self.recv_GetExtendedUrls()

    def send_GetExtendedUrls(self, req_id, shortened_urls, carrier):
        self._oprot.writeMessageBegin('GetExtendedUrls', TMessageType.CALL, self._seqid)
        args = GetExtendedUrls_args()
        args.req_id = req_id
        args.shortened_urls = shortened_urls
        args.carrier = carrier
        args.write(self._oprot)
        self._oprot.writeMessageEnd()
        self._oprot.trans.flush()

    def recv_GetExtendedUrls(self):
        iprot = self._iprot
        (fname, mtype, rseqid) = iprot.readMessageBegin()
        if mtype == TMessageType.EXCEPTION:
            x = TApplicationException()
            x.read(iprot)
            iprot.readMessageEnd()
            raise x
        result = GetExtendedUrls_result()
        result.read(iprot)
        iprot.readMessageEnd()
        if result.success is not None:
            return result.success
        if result.se is not None:
            raise result.se
        raise TApplicationException(TApplicationException.MISSING_RESULT, "GetExtendedUrls failed: unknown result")


class Processor(Iface, TProcessor):
    def __init__(self, handler):
        self._handler = handler
        self._processMap = {}
        self._processMap["ComposeUrls"] = Processor.process_ComposeUrls
        self._processMap["GetExtendedUrls"] = Processor.process_GetExtendedUrls
        self._on_message_begin = None

    def on_message_begin(self, func):
        self._on_message_begin = func

    def process(self, iprot, oprot):
        (name, type, seqid) = iprot.readMessageBegin()
        if self._on_message_begin:
            self._on_message_begin(name, type, seqid)
        if name not in self._processMap:
            iprot.skip(TType.STRUCT)
            iprot.readMessageEnd()
            x = TApplicationException(TApplicationException.UNKNOWN_METHOD, 'Unknown function %s' % (name))
            oprot.writeMessageBegin(name, TMessageType.EXCEPTION, seqid)
            x.write(oprot)
            oprot.writeMessageEnd()
            oprot.trans.flush()
            return
        else:
            self._processMap[name](self, seqid, iprot, oprot)
        return True

    def process_ComposeUrls(self, seqid, iprot, oprot):
        args = ComposeUrls_args()
        args.read(iprot)
        iprot.readMessageEnd()
        result = ComposeUrls_result()
        try:
            result.success = self._handler.ComposeUrls(args.req_id, args.urls, args.carrier)
            msg_type = TMessageType.REPLY
        except TTransport.TTransportException:
            raise
        except ServiceException as se:
            msg_type = TMessageType.REPLY
            result.se = se
        except TApplicationException as ex:
            logging.exception('TApplication exception in handler')
            msg_type = TMessageType.EXCEPTION
            result = ex
        except Exception:
            logging.exception('Unexpected exception in handler')
            msg_type = TMessageType.EXCEPTION
            result = TApplicationException(TApplicationException.INTERNAL_ERROR, 'Internal error')
        oprot.writeMessageBegin("ComposeUrls", msg_type, seqid)
        result.write(oprot)
        oprot.writeMessageEnd()
        oprot.trans.flush()

    def process_GetExtendedUrls(self, seqid, iprot, oprot):
        args = GetExtendedUrls_args()
        args.read(iprot)
        iprot.readMessageEnd()
        result = GetExtendedUrls_result()
        try:
            result.success = self._handler.GetExtendedUrls(args.req_id, args.shortened_urls, args.carrier)
            msg_type = TMessageType.REPLY
        except TTransport.TTransportException:
            raise
        except ServiceException as se:
            msg_type = TMessageType.REPLY
            result.se = se
        except TApplicationException as ex:
            logging.exception('TApplication exception in handler')
            msg_type = TMessageType.EXCEPTION
            result = ex
        except Exception:
            logging.exception('Unexpected exception in handler')
            msg_type = TMessageType.EXCEPTION
            result = TApplicationException(TApplicationException.INTERNAL_ERROR, 'Internal error')
        oprot.writeMessageBegin("GetExtendedUrls", msg_type, seqid)
        result.write(oprot)
        oprot.writeMessageEnd()
        oprot.trans.flush()

# HELPER FUNCTIONS AND STRUCTURES


class ComposeUrls_args(object):
    """
    Attributes:
     - req_id
     - urls
     - carrier

    """


    def __init__(self, req_id=None, urls=None, carrier=None,):
        self.req_id = req_id
        self.urls = urls
        self.carrier = carrier

    def read(self, iprot):
        if iprot._fast_decode is not None and isinstance(iprot.trans, TTransport.CReadableTransport) and self.thrift_spec is not None:
            iprot._fast_decode(self, iprot, [self.__class__, self.thrift_spec])
            return
        iprot.readStructBegin()
        while True:
            (fname, ftype, fid) = iprot.readFieldBegin()
            if ftype == TType.STOP:
                break
            if fid == 1:
                if ftype == TType.I64:
                    self.req_id = iprot.readI64()
                else:
                    iprot.skip(ftype)
            elif fid == 2:
                if ftype == TType.LIST:
                    self.urls = []
                    (_etype386, _size383) = iprot.readListBegin()
                    for _i387 in range(_size383):
                        _elem388 = iprot.readString().decode('utf-8', errors='replace') if sys.version_info[0] == 2 else iprot.readString()
                        self.urls.append(_elem388)
                    iprot.readListEnd()
                else:
                    iprot.skip(ftype)
            elif fid == 3:
                if ftype == TType.MAP:
                    self.carrier = {}
                    (_ktype390, _vtype391, _size389) = iprot.readMapBegin()
                    for _i393 in range(_size389):
                        _key394 = iprot.readString().decode('utf-8', errors='replace') if sys.version_info[0] == 2 else iprot.readString()
                        _val395 = iprot.readString().decode('utf-8', errors='replace') if sys.version_info[0] == 2 else iprot.readString()
                        self.carrier[_key394] = _val395
                    iprot.readMapEnd()
                else:
                    iprot.skip(ftype)
            else:
                iprot.skip(ftype)
            iprot.readFieldEnd()
        iprot.readStructEnd()

    def write(self, oprot):
        if oprot._fast_encode is not None and self.thrift_spec is not None:
            oprot.trans.write(oprot._fast_encode(self, [self.__class__, self.thrift_spec]))
            return
        oprot.writeStructBegin('ComposeUrls_args')
        if self.req_id is not None:
            oprot.writeFieldBegin('req_id', TType.I64, 1)
            oprot.writeI64(self.req_id)
            oprot.writeFieldEnd()
        if self.urls is not None:
            oprot.writeFieldBegin('urls', TType.LIST, 2)
            oprot.writeListBegin(TType.STRING, len(self.urls))
            for iter396 in self.urls:
                oprot.writeString(iter396.encode('utf-8') if sys.version_info[0] == 2 else iter396)
            oprot.writeListEnd()
            oprot.writeFieldEnd()
        if self.carrier is not None:
            oprot.writeFieldBegin('carrier', TType.MAP, 3)
            oprot.writeMapBegin(TType.STRING, TType.STRING, len(self.carrier))
            for kiter397, viter398 in self.carrier.items():
                oprot.writeString(kiter397.encode('utf-8') if sys.version_info[0] == 2 else kiter397)
                oprot.writeString(viter398.encode('utf-8') if sys.version_info[0] == 2 else viter398)
            oprot.writeMapEnd()
            oprot.writeFieldEnd()
        oprot.writeFieldStop()
        oprot.writeStructEnd()

    def validate(self):
        return

    def __repr__(self):
        L = ['%s=%r' % (key, value)
             for key, value in self.__dict__.items()]
        return '%s(%s)' % (self.__class__.__name__, ', '.join(L))

    def __eq__(self, other):
        return isinstance(other, self.__class__) and self.__dict__ == other.__dict__

    def __ne__(self, other):
        return not (self == other)
all_structs.append(ComposeUrls_args)
ComposeUrls_args.thrift_spec = (
    None,  # 0
    (1, TType.I64, 'req_id', None, None, ),  # 1
    (2, TType.LIST, 'urls', (TType.STRING, 'UTF8', False), None, ),  # 2
    (3, TType.MAP, 'carrier', (TType.STRING, 'UTF8', TType.STRING, 'UTF8', False), None, ),  # 3
)


class ComposeUrls_result(object):
    """
    Attributes:
     - success
     - se

    """


    def __init__(self, success=None, se=None,):
        self.success = success
        self.se = se

    def read(self, iprot):
        if iprot._fast_decode is not None and isinstance(iprot.trans, TTransport.CReadableTransport) and self.thrift_spec is not None:
            iprot._fast_decode(self, iprot, [self.__class__, self.thrift_spec])
            return
        iprot.readStructBegin()
        while True:
            (fname, ftype, fid) = iprot.readFieldBegin()
            if ftype == TType.STOP:
                break
            if fid == 0:
                if ftype == TType.LIST:
                    self.success = []
                    (_etype402, _size399) = iprot.readListBegin()
                    for _i403 in range(_size399):
                        _elem404 = Url()
                        _elem404.read(iprot)
                        self.success.append(_elem404)
                    iprot.readListEnd()
                else:
                    iprot.skip(ftype)
            elif fid == 1:
                if ftype == TType.STRUCT:
                    self.se = ServiceException.read(iprot)
                else:
                    iprot.skip(ftype)
            else:
                iprot.skip(ftype)
            iprot.readFieldEnd()
        iprot.readStructEnd()

    def write(self, oprot):
        if oprot._fast_encode is not None and self.thrift_spec is not None:
            oprot.trans.write(oprot._fast_encode(self, [self.__class__, self.thrift_spec]))
            return
        oprot.writeStructBegin('ComposeUrls_result')
        if self.success is not None:
            oprot.writeFieldBegin('success', TType.LIST, 0)
            oprot.writeListBegin(TType.STRUCT, len(self.success))
            for iter405 in self.success:
                iter405.write(oprot)
            oprot.writeListEnd()
            oprot.writeFieldEnd()
        if self.se is not None:
            oprot.writeFieldBegin('se', TType.STRUCT, 1)
            self.se.write(oprot)
            oprot.writeFieldEnd()
        oprot.writeFieldStop()
        oprot.writeStructEnd()

    def validate(self):
        return

    def __repr__(self):
        L = ['%s=%r' % (key, value)
             for key, value in self.__dict__.items()]
        return '%s(%s)' % (self.__class__.__name__, ', '.join(L))

    def __eq__(self, other):
        return isinstance(other, self.__class__) and self.__dict__ == other.__dict__

    def __ne__(self, other):
        return not (self == other)
all_structs.append(ComposeUrls_result)
ComposeUrls_result.thrift_spec = (
    (0, TType.LIST, 'success', (TType.STRUCT, [Url, None], False), None, ),  # 0
    (1, TType.STRUCT, 'se', [ServiceException, None], None, ),  # 1
)


class GetExtendedUrls_args(object):
    """
    Attributes:
     - req_id
     - shortened_urls
     - carrier

    """


    def __init__(self, req_id=None, shortened_urls=None, carrier=None,):
        self.req_id = req_id
        self.shortened_urls = shortened_urls
        self.carrier = carrier

    def read(self, iprot):
        if iprot._fast_decode is not None and isinstance(iprot.trans, TTransport.CReadableTransport) and self.thrift_spec is not None:
            iprot._fast_decode(self, iprot, [self.__class__, self.thrift_spec])
            return
        iprot.readStructBegin()
        while True:
            (fname, ftype, fid) = iprot.readFieldBegin()
            if ftype == TType.STOP:
                break
            if fid == 1:
                if ftype == TType.I64:
                    self.req_id = iprot.readI64()
                else:
                    iprot.skip(ftype)
            elif fid == 2:
                if ftype == TType.LIST:
                    self.shortened_urls = []
                    (_etype409, _size406) = iprot.readListBegin()
                    for _i410 in range(_size406):
                        _elem411 = iprot.readString().decode('utf-8', errors='replace') if sys.version_info[0] == 2 else iprot.readString()
                        self.shortened_urls.append(_elem411)
                    iprot.readListEnd()
                else:
                    iprot.skip(ftype)
            elif fid == 3:
                if ftype == TType.MAP:
                    self.carrier = {}
                    (_ktype413, _vtype414, _size412) = iprot.readMapBegin()
                    for _i416 in range(_size412):
                        _key417 = iprot.readString().decode('utf-8', errors='replace') if sys.version_info[0] == 2 else iprot.readString()
                        _val418 = iprot.readString().decode('utf-8', errors='replace') if sys.version_info[0] == 2 else iprot.readString()
                        self.carrier[_key417] = _val418
                    iprot.readMapEnd()
                else:
                    iprot.skip(ftype)
            else:
                iprot.skip(ftype)
            iprot.readFieldEnd()
        iprot.readStructEnd()

    def write(self, oprot):
        if oprot._fast_encode is not None and self.thrift_spec is not None:
            oprot.trans.write(oprot._fast_encode(self, [self.__class__, self.thrift_spec]))
            return
        oprot.writeStructBegin('GetExtendedUrls_args')
        if self.req_id is not None:
            oprot.writeFieldBegin('req_id', TType.I64, 1)
            oprot.writeI64(self.req_id)
            oprot.writeFieldEnd()
        if self.shortened_urls is not None:
            oprot.writeFieldBegin('shortened_urls', TType.LIST, 2)
            oprot.writeListBegin(TType.STRING, len(self.shortened_urls))
            for iter419 in self.shortened_urls:
                oprot.writeString(iter419.encode('utf-8') if sys.version_info[0] == 2 else iter419)
            oprot.writeListEnd()
            oprot.writeFieldEnd()
        if self.carrier is not None:
            oprot.writeFieldBegin('carrier', TType.MAP, 3)
            oprot.writeMapBegin(TType.STRING, TType.STRING, len(self.carrier))
            for kiter420, viter421 in self.carrier.items():
                oprot.writeString(kiter420.encode('utf-8') if sys.version_info[0] == 2 else kiter420)
                oprot.writeString(viter421.encode('utf-8') if sys.version_info[0] == 2 else viter421)
            oprot.writeMapEnd()
            oprot.writeFieldEnd()
        oprot.writeFieldStop()
        oprot.writeStructEnd()

    def validate(self):
        return

    def __repr__(self):
        L = ['%s=%r' % (key, value)
             for key, value in self.__dict__.items()]
        return '%s(%s)' % (self.__class__.__name__, ', '.join(L))

    def __eq__(self, other):
        return isinstance(other, self.__class__) and self.__dict__ == other.__dict__

    def __ne__(self, other):
        return not (self == other)
all_structs.append(GetExtendedUrls_args)
GetExtendedUrls_args.thrift_spec = (
    None,  # 0
    (1, TType.I64, 'req_id', None, None, ),  # 1
    (2, TType.LIST, 'shortened_urls', (TType.STRING, 'UTF8', False), None, ),  # 2
    (3, TType.MAP, 'carrier', (TType.STRING, 'UTF8', TType.STRING, 'UTF8', False), None, ),  # 3
)


class GetExtendedUrls_result(object):
    """
    Attributes:
     - success
     - se

    """


    def __init__(self, success=None, se=None,):
        self.success = success
        self.se = se

    def read(self, iprot):
        if iprot._fast_decode is not None and isinstance(iprot.trans, TTransport.CReadableTransport) and self.thrift_spec is not None:
            iprot._fast_decode(self, iprot, [self.__class__, self.thrift_spec])
            return
        iprot.readStructBegin()
        while True:
            (fname, ftype, fid) = iprot.readFieldBegin()
            if ftype == TType.STOP:
                break
            if fid == 0:
                if ftype == TType.LIST:
                    self.success = []
                    (_etype425, _size422) = iprot.readListBegin()
                    for _i426 in range(_size422):
                        _elem427 = iprot.readString().decode('utf-8', errors='replace') if sys.version_info[0] == 2 else iprot.readString()
                        self.success.append(_elem427)
                    iprot.readListEnd()
                else:
                    iprot.skip(ftype)
            elif fid == 1:
                if ftype == TType.STRUCT:
                    self.se = ServiceException.read(iprot)
                else:
                    iprot.skip(ftype)
            else:
                iprot.skip(ftype)
            iprot.readFieldEnd()
        iprot.readStructEnd()

    def write(self, oprot):
        if oprot._fast_encode is not None and self.thrift_spec is not None:
            oprot.trans.write(oprot._fast_encode(self, [self.__class__, self.thrift_spec]))
            return
        oprot.writeStructBegin('GetExtendedUrls_result')
        if self.success is not None:
            oprot.writeFieldBegin('success', TType.LIST, 0)
            oprot.writeListBegin(TType.STRING, len(self.success))
            for iter428 in self.success:
                oprot.writeString(iter428.encode('utf-8') if sys.version_info[0] == 2 else iter428)
            oprot.writeListEnd()
            oprot.writeFieldEnd()
        if self.se is not None:
            oprot.writeFieldBegin('se', TType.STRUCT, 1)
            self.se.write(oprot)
            oprot.writeFieldEnd()
        oprot.writeFieldStop()
        oprot.writeStructEnd()

    def validate(self):
        return

    def __repr__(self):
        L = ['%s=%r' % (key, value)
             for key, value in self.__dict__.items()]
        return '%s(%s)' % (self.__class__.__name__, ', '.join(L))

    def __eq__(self, other):
        return isinstance(other, self.__class__) and self.__dict__ == other.__dict__

    def __ne__(self, other):
        return not (self == other)
all_structs.append(GetExtendedUrls_result)
GetExtendedUrls_result.thrift_spec = (
    (0, TType.LIST, 'success', (TType.STRING, 'UTF8', False), None, ),  # 0
    (1, TType.STRUCT, 'se', [ServiceException, None], None, ),  # 1
)
fix_spec(all_structs)
del all_structs
