// Generated by BUCKLESCRIPT, PLEASE EDIT WITH CARE
'use strict';

var List = require("bs-platform/lib/js/list.js");
var Method = require("./Method.bs.js");

function starting(app, port) {
  return app.listen(port);
}

function methodSelected(methodOfRequest, uriRequest, routers) {
  return List.find_opt((function (router) {
                if (router.method === methodOfRequest) {
                  return router.uri === uriRequest;
                } else {
                  return false;
                }
              }), routers);
}

function transformTring(method_) {
  return String(method_);
}

function renderRouterItem(method_, uri) {
  console.log(Method.methodString(method_) + (": " + uri));
  
}

function renderRouters(routers) {
  return List.map((function (router) {
                return renderRouterItem(router.method, router.uri);
              }), routers);
}

exports.starting = starting;
exports.methodSelected = methodSelected;
exports.transformTring = transformTring;
exports.renderRouterItem = renderRouterItem;
exports.renderRouters = renderRouters;
/* No side effect */