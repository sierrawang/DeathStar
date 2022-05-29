import sys
sys.path.append('../gen-py')

import random
from social_network import UserTimelineStorageService
from social_network.ttypes import ServiceException

from thrift import Thrift
from thrift.transport import TSocket
from thrift.transport import TTransport
from thrift.protocol import TBinaryProtocol

def update_user():
  socket = TSocket.TSocket("localhost", 10012)
  transport = TTransport.TFramedTransport(socket)
  protocol = TBinaryProtocol.TBinaryProtocol(transport)
  client = UserTimelineStorageService.Client(protocol)

  transport.open()
  # client.UpdateUserTimeline(user_id, post_id, timestamp)
  client.UpdateUserTimeline(0, 0, 0)
  client.UpdateUserTimeline(0, 1, 1)
  client.UpdateUserTimeline(0, 3, 4)
  client.UpdateUserTimeline(0, 4, 3)
  transport.close()

def get_user():
  socket = TSocket.TSocket("localhost", 10012)
  transport = TTransport.TFramedTransport(socket)
  protocol = TBinaryProtocol.TBinaryProtocol(transport)
  client = UserTimelineStorageService.Client(protocol)

  transport.open()
  res = client.GetUserTimeline(0, 0, 5)

  # This one should fail
  res = client.GetUserTimeline(1, 0, 2)
  transport.close()
  print(res)

if __name__ == '__main__':
  try:
    update_user()
    get_user()
  except ServiceException as se:
    print('%s' % se.message)
  except Thrift.TException as tx:
    print('%s' % tx.message)