import sys
sys.path.append('/home/jrpear/repos/DeathStarBench/socialNetwork/gen-py')

import uuid
from social_network import UserStorageService
from social_network.ttypes import ServiceException
from social_network.ttypes import User

from thrift import Thrift
from thrift.transport import TSocket
from thrift.transport import TTransport
from thrift.protocol import TBinaryProtocol

def write_then_read():
  socket = TSocket.TSocket("localhost", 10011)
  transport = TTransport.TFramedTransport(socket)
  protocol = TBinaryProtocol.TBinaryProtocol(transport)
  client = UserStorageService.Client(protocol)
  transport.open()
  user = User(user_id=1, first_name="first_name_1", last_name="last_name_1", username="username_1", password_hashed="password_1", salt="salt_1",)
  client.WriteUser(user)
  print(client.ReadUser(1))
  print(client.ReadUser(5))
  transport.close()

if __name__ == '__main__':
  try:
    write_then_read()
  except ServiceException as se:
    print('%s' % se.message)
  except Thrift.TException as tx:
    print('%s' % tx.message)
