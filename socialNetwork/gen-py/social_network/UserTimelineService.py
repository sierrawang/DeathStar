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
    def WriteUserTimeline(self, req_id, post_id, user_id, timestamp, carrier):
        """
        Parameters:
         - req_id
         - post_id
         - user_id
         - timestamp
         - carrier

        """
        pass

    def ReadUserTimeline(self, req_id, user_id, start, stop, carrier):
        """
        Parameters:
         - req_id
         - user_id
         - start
         - stop
         - carrier

        """
        pass


class Client(Iface):
    def __init__(self, iprot, oprot=None):
        self._iprot = self._oprot = iprot
        if oprot is not None:
            self._oprot = oprot
        self._seqid = 0

    def WriteUserTimeline(self, req_id, post_id, user_id, timestamp, carrier):
        """
        Parameters:
         - req_id
         - post_id
         - user_id
         - timestamp
         - carrier

        """
        self.send_WriteUserTimeline(req_id, post_id, user_id, timestamp, carrier)
        self.recv_WriteUserTimeline()

    def send_WriteUserTimeline(self, req_id, post_id, user_id, timestamp, carrier):
        self._oprot.writeMessageBegin('WriteUserTimeline', TMessageType.CALL, self._seqid)
        args = WriteUserTimeline_args()
        args.req_id = req_id
        args.post_id = post_id
        args.user_id = user_id
        args.timestamp = timestamp
        args.carrier = carrier
        args.write(self._oprot)
        self._oprot.writeMessageEnd()
        self._oprot.trans.flush()

    def recv_WriteUserTimeline(self):
        iprot = self._iprot
        (fname, mtype, rseqid) = iprot.readMessageBegin()
        if mtype == TMessageType.EXCEPTION:
            x = TApplicationException()
            x.read(iprot)
            iprot.readMessageEnd()
            raise x
        result = WriteUserTimeline_result()
        result.read(iprot)
        iprot.readMessageEnd()
        if result.se is not None:
            raise result.se
        return

    def ReadUserTimeline(self, req_id, user_id, start, stop, carrier):
        """
        Parameters:
         - req_id
         - user_id
         - start
         - stop
         - carrier

        """
        self.send_ReadUserTimeline(req_id, user_id, start, stop, carrier)
        return self.recv_ReadUserTimeline()

    def send_ReadUserTimeline(self, req_id, user_id, start, stop, carrier):
        self._oprot.writeMessageBegin('ReadUserTimeline', TMessageType.CALL, self._seqid)
        args = ReadUserTimeline_args()
        args.req_id = req_id
        args.user_id = user_id
        args.start = start
        args.stop = stop
        args.carrier = carrier
        args.write(self._oprot)
        self._oprot.writeMessageEnd()
        self._oprot.trans.flush()

    def recv_ReadUserTimeline(self):
        iprot = self._iprot
        (fname, mtype, rseqid) = iprot.readMessageBegin()
        if mtype == TMessageType.EXCEPTION:
            x = TApplicationException()
            x.read(iprot)
            iprot.readMessageEnd()
            raise x
        result = ReadUserTimeline_result()
        result.read(iprot)
        iprot.readMessageEnd()
        if result.success is not None:
            return result.success
        if result.se is not None:
            raise result.se
        raise TApplicationException(TApplicationException.MISSING_RESULT, "ReadUserTimeline failed: unknown result")


class Processor(Iface, TProcessor):
    def __init__(self, handler):
        self._handler = handler
        self._processMap = {}
        self._processMap["WriteUserTimeline"] = Processor.process_WriteUserTimeline
        self._processMap["ReadUserTimeline"] = Processor.process_ReadUserTimeline
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

    def process_WriteUserTimeline(self, seqid, iprot, oprot):
        args = WriteUserTimeline_args()
        args.read(iprot)
        iprot.readMessageEnd()
        result = WriteUserTimeline_result()
        try:
            self._handler.WriteUserTimeline(args.req_id, args.post_id, args.user_id, args.timestamp, args.carrier)
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
        oprot.writeMessageBegin("WriteUserTimeline", msg_type, seqid)
        result.write(oprot)
        oprot.writeMessageEnd()
        oprot.trans.flush()

    def process_ReadUserTimeline(self, seqid, iprot, oprot):
        args = ReadUserTimeline_args()
        args.read(iprot)
        iprot.readMessageEnd()
        result = ReadUserTimeline_result()
        try:
            result.success = self._handler.ReadUserTimeline(args.req_id, args.user_id, args.start, args.stop, args.carrier)
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
        oprot.writeMessageBegin("ReadUserTimeline", msg_type, seqid)
        result.write(oprot)
        oprot.writeMessageEnd()
        oprot.trans.flush()

# HELPER FUNCTIONS AND STRUCTURES


class WriteUserTimeline_args(object):
    """
    Attributes:
     - req_id
     - post_id
     - user_id
     - timestamp
     - carrier

    """


    def __init__(self, req_id=None, post_id=None, user_id=None, timestamp=None, carrier=None,):
        self.req_id = req_id
        self.post_id = post_id
        self.user_id = user_id
        self.timestamp = timestamp
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
                if ftype == TType.I64:
                    self.post_id = iprot.readI64()
                else:
                    iprot.skip(ftype)
            elif fid == 3:
                if ftype == TType.I64:
                    self.user_id = iprot.readI64()
                else:
                    iprot.skip(ftype)
            elif fid == 4:
                if ftype == TType.I64:
                    self.timestamp = iprot.readI64()
                else:
                    iprot.skip(ftype)
            elif fid == 5:
                if ftype == TType.MAP:
                    self.carrier = {}
                    (_ktype252, _vtype253, _size251) = iprot.readMapBegin()
                    for _i255 in range(_size251):
                        _key256 = iprot.readString().decode('utf-8', errors='replace') if sys.version_info[0] == 2 else iprot.readString()
                        _val257 = iprot.readString().decode('utf-8', errors='replace') if sys.version_info[0] == 2 else iprot.readString()
                        self.carrier[_key256] = _val257
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
        oprot.writeStructBegin('WriteUserTimeline_args')
        if self.req_id is not None:
            oprot.writeFieldBegin('req_id', TType.I64, 1)
            oprot.writeI64(self.req_id)
            oprot.writeFieldEnd()
        if self.post_id is not None:
            oprot.writeFieldBegin('post_id', TType.I64, 2)
            oprot.writeI64(self.post_id)
            oprot.writeFieldEnd()
        if self.user_id is not None:
            oprot.writeFieldBegin('user_id', TType.I64, 3)
            oprot.writeI64(self.user_id)
            oprot.writeFieldEnd()
        if self.timestamp is not None:
            oprot.writeFieldBegin('timestamp', TType.I64, 4)
            oprot.writeI64(self.timestamp)
            oprot.writeFieldEnd()
        if self.carrier is not None:
            oprot.writeFieldBegin('carrier', TType.MAP, 5)
            oprot.writeMapBegin(TType.STRING, TType.STRING, len(self.carrier))
            for kiter258, viter259 in self.carrier.items():
                oprot.writeString(kiter258.encode('utf-8') if sys.version_info[0] == 2 else kiter258)
                oprot.writeString(viter259.encode('utf-8') if sys.version_info[0] == 2 else viter259)
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
all_structs.append(WriteUserTimeline_args)
WriteUserTimeline_args.thrift_spec = (
    None,  # 0
    (1, TType.I64, 'req_id', None, None, ),  # 1
    (2, TType.I64, 'post_id', None, None, ),  # 2
    (3, TType.I64, 'user_id', None, None, ),  # 3
    (4, TType.I64, 'timestamp', None, None, ),  # 4
    (5, TType.MAP, 'carrier', (TType.STRING, 'UTF8', TType.STRING, 'UTF8', False), None, ),  # 5
)


class WriteUserTimeline_result(object):
    """
    Attributes:
     - se

    """


    def __init__(self, se=None,):
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
            if fid == 1:
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
        oprot.writeStructBegin('WriteUserTimeline_result')
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
all_structs.append(WriteUserTimeline_result)
WriteUserTimeline_result.thrift_spec = (
    None,  # 0
    (1, TType.STRUCT, 'se', [ServiceException, None], None, ),  # 1
)


class ReadUserTimeline_args(object):
    """
    Attributes:
     - req_id
     - user_id
     - start
     - stop
     - carrier

    """


    def __init__(self, req_id=None, user_id=None, start=None, stop=None, carrier=None,):
        self.req_id = req_id
        self.user_id = user_id
        self.start = start
        self.stop = stop
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
                if ftype == TType.I64:
                    self.user_id = iprot.readI64()
                else:
                    iprot.skip(ftype)
            elif fid == 3:
                if ftype == TType.I32:
                    self.start = iprot.readI32()
                else:
                    iprot.skip(ftype)
            elif fid == 4:
                if ftype == TType.I32:
                    self.stop = iprot.readI32()
                else:
                    iprot.skip(ftype)
            elif fid == 5:
                if ftype == TType.MAP:
                    self.carrier = {}
                    (_ktype261, _vtype262, _size260) = iprot.readMapBegin()
                    for _i264 in range(_size260):
                        _key265 = iprot.readString().decode('utf-8', errors='replace') if sys.version_info[0] == 2 else iprot.readString()
                        _val266 = iprot.readString().decode('utf-8', errors='replace') if sys.version_info[0] == 2 else iprot.readString()
                        self.carrier[_key265] = _val266
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
        oprot.writeStructBegin('ReadUserTimeline_args')
        if self.req_id is not None:
            oprot.writeFieldBegin('req_id', TType.I64, 1)
            oprot.writeI64(self.req_id)
            oprot.writeFieldEnd()
        if self.user_id is not None:
            oprot.writeFieldBegin('user_id', TType.I64, 2)
            oprot.writeI64(self.user_id)
            oprot.writeFieldEnd()
        if self.start is not None:
            oprot.writeFieldBegin('start', TType.I32, 3)
            oprot.writeI32(self.start)
            oprot.writeFieldEnd()
        if self.stop is not None:
            oprot.writeFieldBegin('stop', TType.I32, 4)
            oprot.writeI32(self.stop)
            oprot.writeFieldEnd()
        if self.carrier is not None:
            oprot.writeFieldBegin('carrier', TType.MAP, 5)
            oprot.writeMapBegin(TType.STRING, TType.STRING, len(self.carrier))
            for kiter267, viter268 in self.carrier.items():
                oprot.writeString(kiter267.encode('utf-8') if sys.version_info[0] == 2 else kiter267)
                oprot.writeString(viter268.encode('utf-8') if sys.version_info[0] == 2 else viter268)
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
all_structs.append(ReadUserTimeline_args)
ReadUserTimeline_args.thrift_spec = (
    None,  # 0
    (1, TType.I64, 'req_id', None, None, ),  # 1
    (2, TType.I64, 'user_id', None, None, ),  # 2
    (3, TType.I32, 'start', None, None, ),  # 3
    (4, TType.I32, 'stop', None, None, ),  # 4
    (5, TType.MAP, 'carrier', (TType.STRING, 'UTF8', TType.STRING, 'UTF8', False), None, ),  # 5
)


class ReadUserTimeline_result(object):
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
                    (_etype272, _size269) = iprot.readListBegin()
                    for _i273 in range(_size269):
                        _elem274 = Post()
                        _elem274.read(iprot)
                        self.success.append(_elem274)
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
        oprot.writeStructBegin('ReadUserTimeline_result')
        if self.success is not None:
            oprot.writeFieldBegin('success', TType.LIST, 0)
            oprot.writeListBegin(TType.STRUCT, len(self.success))
            for iter275 in self.success:
                iter275.write(oprot)
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
all_structs.append(ReadUserTimeline_result)
ReadUserTimeline_result.thrift_spec = (
    (0, TType.LIST, 'success', (TType.STRUCT, [Post, None], False), None, ),  # 0
    (1, TType.STRUCT, 'se', [ServiceException, None], None, ),  # 1
)
fix_spec(all_structs)
del all_structs
