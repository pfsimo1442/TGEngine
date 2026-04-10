#pragma once
#include "tgTexture.h"

namespace tg::graphics
{
	// 렌더타겟의 포맷을 지정하는 열거형
	enum class eRenderTragetFormat
	{
		None = 0,
		RGBA8, // Color
		RED_INTEGER, // RED 채널에 정수형 데이터 저장 (정수형 데이터 저장을 용도로 사용)
		DEPTH24STENCIL8, // Depth/stencil
		SHADER_RESOURCE, // Shader resource
		Depth = DEPTH24STENCIL8 // Defaults
	};

	struct RenderTargetTextureSpecification
	{
		RenderTargetTextureSpecification() = default;
		RenderTargetTextureSpecification(eRenderTragetFormat format)
			: TextureFormat(format) {
		}

		eRenderTragetFormat TextureFormat = eRenderTragetFormat::None;
	};

	struct RenderTargetAttachmentSpecification
	{
		RenderTargetAttachmentSpecification() = default;
		RenderTargetAttachmentSpecification(std::initializer_list<RenderTargetTextureSpecification> attachments)
			: Attachments(attachments) {
		}

		std::vector<RenderTargetTextureSpecification> Attachments;
	};

	struct RenderTargetSpecification
	{
		UINT Width = 0, Height = 0;
		RenderTargetAttachmentSpecification Attachments;
		UINT Samples = 1;

		bool SwapChainTarget = false;
	};

	class RenderTarget
	{
	public:
		RenderTarget(const RenderTargetSpecification& spec);
		virtual ~RenderTarget();

		static RenderTarget* Create(const RenderTargetSpecification& spec);

		void Invalidate();
		void Bind();
		void Unbind();

		void Resize(UINT width, UINT height);
		int ReadPixel(uint32_t attachmentIndex, int x, int y);

		void ClearAttachment(UINT index, const void* value);

		Texture* GetAttachmentTexture(UINT index) { if (index >= mAttachments.size()) assert(NULL && "Rendertarget is not exist"); return mAttachments[index]; }
		RenderTargetSpecification& GetSpecification() { return mSpecification; }

	private:
		RenderTargetSpecification mSpecification;

		std::vector<RenderTargetTextureSpecification> mSpecifications;
		RenderTargetTextureSpecification mDepthAttachmentSpecification;

		std::vector<Texture*> mAttachments;
		Texture* mDepthAttachment;
	};
}