/*
 * Copyright (c) 2016, Tino Rusch
 *
 * This file is released under the terms of the MIT license. You can find the
 * complete text in the attached LICENSE file or online at:
 *
 * http://www.opensource.org/licenses/mit-license.php
 *
 * @author: Tino Rusch (tino.rusch@webvariants.de)
 */

#include "susi/Authenticator.h"
#include "susi/BaseApp.h"

class AuthenticatorApp : public Susi::BaseApp {
protected:
  std::shared_ptr<Susi::Authenticator> _authenticator;

public:
  AuthenticatorApp(int argc, char **argv) : Susi::BaseApp{argc, argv} {}
  virtual ~AuthenticatorApp() {}
  virtual void start() override {
    _authenticator.reset(new Susi::Authenticator{*_susi, _config["component"]});
  }
};

int main(int argc, char *argv[]) {
  try {
    AuthenticatorApp app{argc, argv};
    app.start();
    app.join();
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
    return 1;
  }
  return 0;
}
