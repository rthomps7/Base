#!/usr/bin/python
#
# Todo.py: Searches files in directory for todo's with the specified username
# To specify a todo in a file, type TODO(rft) or whatever username.
#
# Author: Robert Thompson
#
# Usage: python todo.py <user> <directory>
#

import sys
import os
import fnmatch
import re

def main():
  assert len(sys.argv) == 3, \
    "Must have 3 arguments: todo <user> <dir>"

  user = sys.argv[1]
  directory = sys.argv[2]

  print user, directory

  matches=[]
  for root, dirnames, filenames in os.walk(directory):
    for filename in [n for n in filenames if match(n)]:
      f = os.path.join(root,filename);
      findTodos(f,user);      

def match(name):
  types = ['py','c','cc','cpp','h']
  for t in types:
    if fnmatch.fnmatch(name,'*.'+t):
      return True
  return False

def findTodos(f,user):
  count = 1
  for line in open(f):
    if re.search('TODO\('+user+'\)', line):
      s = f+':'+str(count)+':'+line
      print s,
    count+=1

if __name__ == '__main__':
  main()
