/* <orly/synth/collated_by_expr.h>

   TODO

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

#pragma once

#include <cassert>

#include <base/class_traits.h>
#include <orly/expr/collated_by.h>
#include <orly/expr/thatable.h>
#include <orly/orly.package.cst.h>
#include <orly/synth/startable_expr.h>
#include <orly/synth/thatable_expr.h>

namespace Orly {

  namespace Synth {

    /* TODO */
    class TExprFactory;

    /* TODO */
    class TCollatedByExpr
        : public TStartableExpr,
          public TThatableExpr {
      NO_COPY(TCollatedByExpr);
      public:

      /* TODO */
      TCollatedByExpr(const TExprFactory *expr_factory, const Package::Syntax::TCollatedByExpr *collated_by_expr);

      /* TODO */
      virtual ~TCollatedByExpr();

      /* TODO */
      virtual Expr::TExpr::TPtr Build() const;

      /* TODO */
      virtual void ForEachInnerScope(const std::function<void (TScope *)> &cb);

      /* TODO */
      virtual void ForEachRef(const std::function<void (TAnyRef &)> &cb);

      /* TODO */
      const Expr::TCollatedBy::TPtr &GetSymbol() const;

      /* TODO */
      virtual Expr::TStartable::TPtr GetStartableSymbol() const;

      /* TODO */
      virtual Expr::TThatable::TPtr GetThatableSymbol() const;

      private:

      /* TODO */
      const Package::Syntax::TCollatedByExpr *CollatedByExpr;

      TExpr *Seq;

      /* TODO */
      TExpr *Reduce;

      /* TODO */
      TExpr *Having;

      /* TODO */
      mutable Expr::TCollatedBy::TPtr Symbol;

    };  // TCollatedByExpr

  }  // Synth

}  // Orly
