// Generated by BUCKLESCRIPT, PLEASE EDIT WITH CARE
'use strict';

var List = require("bs-platform/lib/js/list.js");
var Method = require("./Method.bs.js");

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

exports.transformTring = transformTring;
exports.renderRouterItem = renderRouterItem;
exports.renderRouters = renderRouters;
/* No side effect */
