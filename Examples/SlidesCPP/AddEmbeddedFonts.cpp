#include <Export/SaveFormat.h>
#include <DOM/Presentation.h>
#include <DOM/ISlideCollection.h>
#include <DOM/IMasterSlideCollection.h>
#include <DOM/IMasterSlide.h>
#include <DOM/IShapeCollection.h>
#include <DOM/ShapeType.h>
#include <DOM/Background.h>
#include <DOM/BackgroundType.h>
#include <DOM/GradientFormat.h>
#include <DOM/FillFormat.h>
#include <DOM/ILineFormat.h>
#include <DOM/ILineFillFormat.h>
#include <DOM/PictureFillFormat.h>
#include <DOM/PictureFillMode.h>
#include <DOM/IPPImage.h>
#include <DOM/IImageCollection.h>
#include <DOM/ISlidesPicture.h>
#include <DOM/IColorFormat.h>
#include <DOM/IAutoShape.h>
#include <DOM/AutoShape.h>
#include <DOM/IEffectFormat.h>
#include <DOM/Effects/IInnerShadow.h>
#include <DOM/SchemeColor.h>
#include <DOM/ColorType.h>
#include <DOM/IFontsManager.h>

#include <DOM/FillType.h>
#include <DOM/TileFlip.h>
#include <drawing/imaging/image_format.h>
#include <DOM/Shape.h>
#include <DOM/Presentation.h>
#include <DOM/ITextFrame.h>
#include <DOM/ISlideCollection.h>
#include <DOM/ISlide.h>
#include <DOM/IShapeCollection.h>
#include <DOM/IShape.h>
#include <DOM/TextVerticalType.h>
#include <DOM/TextAnchorType.h>
#include <DOM/IPortionCollection.h>
#include <DOM/IPortion.h>
#include <DOM/IPortionFormat.h>
#include <DOM/IParagraphCollection.h>
#include <DOM/IParagraph.h>
#include <DOM/Fonts/FontData.h>
#include <DOM/IFontData.h>
#include <DOM/NullableBool.h>
#include <DOM/TextUnderlineType.h>
#include <DOM/IParagraphFormat.h>
#include <Export/EmbedFontCharacters.h>


#include <system/object.h>
#include <system/object_ext.h>
#include <system/special_casts.h>
#include <system/io/path.h>
#include <drawing/imaging/image_format.h>
#include <system/string.h>

#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Aspose::Slides::Export;
using namespace System;
using namespace System::Drawing;


void AddEmbeddedFonts()
{

	// ExStart:AddEmbeddedFonts
	// The path to the documents directory.
	const String outPath = u"../out/AddEmbeddedFonts_out.pptx";
	const String templatePath = u"../templates/EmbeddedFonts.pptx";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	// Access first slide
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	SharedPtr<IFontsManager> fontsManager = pres->get_FontsManager();

	// get all embedded fonts
	ArrayPtr<SharedPtr<IFontData>>embeddedFonts = fontsManager->GetEmbeddedFonts();
	ArrayPtr<SharedPtr<IFontData>>allFonts = fontsManager->GetFonts();

	auto enumerator_0 = allFonts->GetEnumerator();
	decltype(enumerator_0->get_Current()) font = enumerator_0->get_Current();
	
	while (enumerator_0->MoveNext() && (font = enumerator_0->get_Current(), true))
	{
		//if (font_0->get_FontName() == font->get_FontName())
		if (embeddedFonts->Contains(font))
		{
			fontsManager->AddEmbeddedFont(font, EmbedFontCharacters::All);
		}
	}

	// save the presentation without embedded "Calibri" font
	pres->Save(outPath, Aspose::Slides::Export::SaveFormat::Pptx);

	// ExEnd:AddEmbeddedFonts
}
