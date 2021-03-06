/* <orly/synth/user_id_expr.cc>

   Implements <orly/synth/user_id_expr.h>.

   Copyright 2010-2014 OrlyAtomics, Inc.

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

     http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License. */

#include <orly/synth/user_id_expr.h>

#include <base/assert_true.h>
#include <orly/expr/user_id.h>
#include <orly/synth/get_pos_range.h>

using namespace Orly;
using namespace Orly::Synth;

TUserIdExpr::TUserIdExpr(const Package::Syntax::TUserIdExpr *user_id_expr)
    : UserIdExpr(Base::AssertTrue(user_id_expr)) {}

Expr::TExpr::TPtr TUserIdExpr::Build() const {
  assert(this);
  return Expr::TUserId::New(GetPosRange(UserIdExpr));
}
