/*
  Licensed to the Apache Software Foundation (ASF) under one
  or more contributor license agreements.  See the NOTICE file
  distributed with this work for additional information
  regarding copyright ownership.  The ASF licenses this file
  to you under the Apache License, Version 2.0 (the
  "License"); you may not use this file except in compliance
  with the License.  You may obtain a copy of the License at

  http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.
*/

#pragma once

#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;

class CookieJar
{
public:
  CookieJar(){};
  ~CookieJar(){};

  bool create(const string &strCookie);

  CookieJar(const CookieJar &)            = delete;
  CookieJar &operator=(const CookieJar &) = delete;

  bool get_full(const string &cookie_name, string &val);
  bool get_part(const string &cookie_name, const string &part_name, string &val);

private:
  int verify_name(char *name);
  int verify_value(char *val, int val_len);
  int parse(const string &arg, const char *sepstr, bool val_check, bool mainElement);

  void addElement(const char *key, const char *val);
  void addSubElement(const char *key, const char *val);

  class CookieVal
  {
  public:
    unordered_map<string, string> m_subelements;
    string                        m_val;
    bool                          parts_inited = false;
  };
  CookieVal *m_currentVal = nullptr;

  unordered_map<string, CookieVal> m_jar;
};
