/* <orly/code_gen/split.cc>

   Implements <orly/code_gen/split.h>

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

#include <orly/code_gen/split.h>

#include <orly/type/seq.h>
#include <orly/type/unwrap.h>

using namespace std;
using namespace Orly::CodeGen;
using namespace Orly::Type;

TSplit::TPtr TSplit::New(
    const L0::TPackage *package,
    const TInline::TPtr &split_text,
    const TInline::TPtr &regex) {
  return TPtr(new TSplit(package, split_text, regex));
}

void TSplit::WriteExpr(TCppPrinter &out) const {
  assert(this);
  assert(&out);
  out
    << "TSplitGenerator::New("
    << SplitThisText << ", " << Regex << ')';
}

TSplit::TSplit(const L0::TPackage *package,
               const TInline::TPtr &split_text,
               const TInline::TPtr &regex)
  : TInline(package, TSplit::GetReturnType()),
    SplitThisText(split_text),
    Regex(regex) {}

/* for convenience/readability */
TType TSplit::GetReturnType() {
  return TSeq::Get(TAddr::Get(vector<pair<TAddrDir, TType>>{{TAddrDir::Asc, TStr::Get()}, {TAddrDir::Asc, TOpt::Get(TStr::Get())}}));
}