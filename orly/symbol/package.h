/* <orly/symbol/package.h>

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

#include <memory>

#include <base/class_traits.h>
#include <orly/package/name.h>
#include <orly/symbol/scope.h>

namespace Orly {

  namespace Symbol {

    /* Top level package. */
    class TPackage
        : public TScope {
      NO_COPY(TPackage);
      public:

      /* Convenience typedef for std::shared_ptr<TPackage> */
      typedef std::shared_ptr<TPackage> TPtr;

      /* Returns a std::shared_ptr to a new TPackage instance */
      static TPtr New(const Package::TName &name, const std::string &index_name, unsigned int version);

      /* Return the Package's namespace. */
      const Package::TName &GetName() const;

      const std::string &GetIndexName() const;

      /* Returns the package version number */
      unsigned int GetVersion() const;

      private:

      /* Do-little */
      TPackage(const Package::TName &name, const std::string &index_name, unsigned int version);

      /* See accessor */
      Package::TName Name;

      std::string IndexName;

      /* See accessor */
      unsigned int Version;

    };  // TPackage

  }  // Symbol

}  // Orly
