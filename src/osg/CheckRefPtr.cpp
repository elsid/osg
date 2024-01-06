#include <osg/CheckRefPtr>
#include <osg/Referenced>
#include <osg/ref_ptr>

#include <utility>

namespace osg {

bool isRefPtrMoveable()
{
    ref_ptr<Referenced> src(new Referenced);
#if __cplusplus >= 201103L
    ref_ptr<Referenced> dst(std::move(src));
#endif
    return src == nullptr;
}

}
