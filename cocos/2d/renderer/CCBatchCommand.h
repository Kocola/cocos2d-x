/****************************************************************************
 Copyright (c) 2013-2014 Chukong Technologies Inc.

 http://www.cocos2d-x.org

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#ifndef _CC_BATCHCOMMAND_H_
#define _CC_BATCHCOMMAND_H_

#include "CCRenderCommand.h"
#include "CCGLProgram.h"
#include "CCRenderCommandPool.h"
#include "kazmath/kazmath.h"

NS_CC_BEGIN

class TextureAtlas;

#define CC_NO_TEXTURE 0

class BatchCommand : public RenderCommand
{
public:

    BatchCommand();
    ~BatchCommand();

    void init(float depth, GLuint texutreID, GLProgram* shader, BlendFunc blendType, TextureAtlas *textureAtlas, const kmMat4& modelViewTransform);

    void execute() const;

protected:
    int32_t _materialID;

    //Maternal
    GLuint _textureID;

    GLProgram* _shader;
//    GLuint _shaderID;

    BlendFunc _blendType;

    TextureAtlas *_textureAtlas;

    // ModelView transform
    kmMat4 _mv;
};
NS_CC_END

#endif //_CC_BATCHCOMMAND_H_
