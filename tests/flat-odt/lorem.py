
from sys import argv;

import subprocess;

def run(command):
    print("\033[33m" f"  $ {' '.join(command)}" "\033[0m");
    result = subprocess.run(command);
    if result.returncode:
        print("\033[31m" "    subcommand failed!");
        exit(1);

executable = argv[1];

run([executable, "-v", "-i", "./examples/flat-odt.guard", "-o", "/tmp/flat-odt.c"]);

run(["gcc", "-Werror", "-Wall", "/tmp/flat-odt.c", "-o", "/tmp/flat-odt", "-lgmp"]);

with open("/tmp/lorem.txt", "w") as stream:
    stream.write("""
<?xml version="1.0" encoding="UTF-8"?>

<office:document xmlns:officeooo="http://openoffice.org/2009/office" xmlns:css3t="http://www.w3.org/TR/css3-text/" xmlns:grddl="http://www.w3.org/2003/g/data-view#" xmlns:xhtml="http://www.w3.org/1999/xhtml" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:xsd="http://www.w3.org/2001/XMLSchema" xmlns:chart="urn:oasis:names:tc:opendocument:xmlns:chart:1.0" xmlns:svg="urn:oasis:names:tc:opendocument:xmlns:svg-compatible:1.0" xmlns:draw="urn:oasis:names:tc:opendocument:xmlns:drawing:1.0" xmlns:rpt="http://openoffice.org/2005/report" xmlns:text="urn:oasis:names:tc:opendocument:xmlns:text:1.0" xmlns:style="urn:oasis:names:tc:opendocument:xmlns:style:1.0" xmlns:meta="urn:oasis:names:tc:opendocument:xmlns:meta:1.0" xmlns:config="urn:oasis:names:tc:opendocument:xmlns:config:1.0" xmlns:xlink="http://www.w3.org/1999/xlink" xmlns:fo="urn:oasis:names:tc:opendocument:xmlns:xsl-fo-compatible:1.0" xmlns:of="urn:oasis:names:tc:opendocument:xmlns:of:1.2" xmlns:dc="http://purl.org/dc/elements/1.1/" xmlns:ooo="http://openoffice.org/2004/office" xmlns:dr3d="urn:oasis:names:tc:opendocument:xmlns:dr3d:1.0" xmlns:formx="urn:openoffice:names:experimental:ooxml-odf-interop:xmlns:form:1.0" xmlns:calcext="urn:org:documentfoundation:names:experimental:calc:xmlns:calcext:1.0" xmlns:drawooo="http://openoffice.org/2010/draw" xmlns:field="urn:openoffice:names:experimental:ooo-ms-interop:xmlns:field:1.0" xmlns:office="urn:oasis:names:tc:opendocument:xmlns:office:1.0" xmlns:table="urn:oasis:names:tc:opendocument:xmlns:table:1.0" xmlns:number="urn:oasis:names:tc:opendocument:xmlns:datastyle:1.0" xmlns:ooow="http://openoffice.org/2004/writer" xmlns:oooc="http://openoffice.org/2004/calc" xmlns:tableooo="http://openoffice.org/2009/table" xmlns:loext="urn:org:documentfoundation:names:experimental:office:xmlns:loext:1.0" xmlns:math="http://www.w3.org/1998/Math/MathML" xmlns:form="urn:oasis:names:tc:opendocument:xmlns:form:1.0" xmlns:script="urn:oasis:names:tc:opendocument:xmlns:script:1.0" xmlns:dom="http://www.w3.org/2001/xml-events" xmlns:xforms="http://www.w3.org/2002/xforms" office:version="1.2" office:mimetype="application/vnd.oasis.opendocument.text">
 <office:meta><meta:creation-date>2023-05-01T18:19:58.748511136</meta:creation-date><dc:date>2023-05-01T18:21:01.845440379</dc:date><meta:editing-duration>PT1M3S</meta:editing-duration><meta:editing-cycles>1</meta:editing-cycles><meta:document-statistic meta:table-count="0" meta:image-count="0" meta:object-count="0" meta:page-count="1" meta:paragraph-count="4" meta:word-count="519" meta:character-count="3521" meta:non-whitespace-character-count="3006"/><meta:generator>LibreOffice/6.4.7.2$Linux_X86_64 LibreOffice_project/40$Build-2</meta:generator></office:meta>
 <office:settings>
  <config:config-item-set config:name="ooo:view-settings">
   <config:config-item config:name="ViewAreaTop" config:type="long">95</config:config-item>
   <config:config-item config:name="ViewAreaLeft" config:type="long">0</config:config-item>
   <config:config-item config:name="ViewAreaWidth" config:type="long">36661</config:config-item>
   <config:config-item config:name="ViewAreaHeight" config:type="long">18013</config:config-item>
   <config:config-item config:name="ShowRedlineChanges" config:type="boolean">true</config:config-item>
   <config:config-item config:name="InBrowseMode" config:type="boolean">false</config:config-item>
   <config:config-item-map-indexed config:name="Views">
    <config:config-item-map-entry>
     <config:config-item config:name="ViewId" config:type="string">view2</config:config-item>
     <config:config-item config:name="ViewLeft" config:type="long">26404</config:config-item>
     <config:config-item config:name="ViewTop" config:type="long">22740</config:config-item>
     <config:config-item config:name="VisibleLeft" config:type="long">0</config:config-item>
     <config:config-item config:name="VisibleTop" config:type="long">95</config:config-item>
     <config:config-item config:name="VisibleRight" config:type="long">36659</config:config-item>
     <config:config-item config:name="VisibleBottom" config:type="long">18106</config:config-item>
     <config:config-item config:name="ZoomType" config:type="short">0</config:config-item>
     <config:config-item config:name="ViewLayoutColumns" config:type="short">1</config:config-item>
     <config:config-item config:name="ViewLayoutBookMode" config:type="boolean">false</config:config-item>
     <config:config-item config:name="ZoomFactor" config:type="short">130</config:config-item>
     <config:config-item config:name="IsSelectedFrame" config:type="boolean">false</config:config-item>
     <config:config-item config:name="AnchoredTextOverflowLegacy" config:type="boolean">false</config:config-item>
    </config:config-item-map-entry>
   </config:config-item-map-indexed>
  </config:config-item-set>
  <config:config-item-set config:name="ooo:configuration-settings">
   <config:config-item config:name="PrintProspect" config:type="boolean">false</config:config-item>
   <config:config-item config:name="PrintReversed" config:type="boolean">false</config:config-item>
   <config:config-item config:name="PrintSingleJobs" config:type="boolean">false</config:config-item>
   <config:config-item config:name="PrintLeftPages" config:type="boolean">true</config:config-item>
   <config:config-item config:name="PrintTables" config:type="boolean">true</config:config-item>
   <config:config-item config:name="PrintControls" config:type="boolean">true</config:config-item>
   <config:config-item config:name="PrintPageBackground" config:type="boolean">true</config:config-item>
   <config:config-item config:name="PrintDrawings" config:type="boolean">true</config:config-item>
   <config:config-item config:name="PrintBlackFonts" config:type="boolean">false</config:config-item>
   <config:config-item config:name="PrintAnnotationMode" config:type="short">0</config:config-item>
   <config:config-item config:name="PrintTextPlaceholder" config:type="boolean">false</config:config-item>
   <config:config-item config:name="EmptyDbFieldHidesPara" config:type="boolean">true</config:config-item>
   <config:config-item config:name="DisableOffPagePositioning" config:type="boolean">false</config:config-item>
   <config:config-item config:name="SubtractFlysAnchoredAtFlys" config:type="boolean">false</config:config-item>
   <config:config-item config:name="PropLineSpacingShrinksFirstLine" config:type="boolean">true</config:config-item>
   <config:config-item config:name="ApplyParagraphMarkFormatToNumbering" config:type="boolean">false</config:config-item>
   <config:config-item config:name="TreatSingleColumnBreakAsPageBreak" config:type="boolean">false</config:config-item>
   <config:config-item config:name="EmbedSystemFonts" config:type="boolean">false</config:config-item>
   <config:config-item config:name="EmbedComplexScriptFonts" config:type="boolean">true</config:config-item>
   <config:config-item config:name="EmbedAsianScriptFonts" config:type="boolean">true</config:config-item>
   <config:config-item config:name="EmbedLatinScriptFonts" config:type="boolean">true</config:config-item>
   <config:config-item config:name="EmbedOnlyUsedFonts" config:type="boolean">false</config:config-item>
   <config:config-item config:name="ContinuousEndnotes" config:type="boolean">false</config:config-item>
   <config:config-item config:name="EmbedFonts" config:type="boolean">false</config:config-item>
   <config:config-item config:name="ClippedPictures" config:type="boolean">false</config:config-item>
   <config:config-item config:name="FloattableNomargins" config:type="boolean">false</config:config-item>
   <config:config-item config:name="UnbreakableNumberings" config:type="boolean">false</config:config-item>
   <config:config-item config:name="HeaderSpacingBelowLastPara" config:type="boolean">false</config:config-item>
   <config:config-item config:name="AllowPrintJobCancel" config:type="boolean">true</config:config-item>
   <config:config-item config:name="UseOldPrinterMetrics" config:type="boolean">false</config:config-item>
   <config:config-item config:name="TabOverMargin" config:type="boolean">false</config:config-item>
   <config:config-item config:name="TabsRelativeToIndent" config:type="boolean">true</config:config-item>
   <config:config-item config:name="UseOldNumbering" config:type="boolean">false</config:config-item>
   <config:config-item config:name="InvertBorderSpacing" config:type="boolean">false</config:config-item>
   <config:config-item config:name="PrintPaperFromSetup" config:type="boolean">false</config:config-item>
   <config:config-item config:name="UpdateFromTemplate" config:type="boolean">true</config:config-item>
   <config:config-item config:name="CurrentDatabaseCommandType" config:type="int">0</config:config-item>
   <config:config-item config:name="LinkUpdateMode" config:type="short">1</config:config-item>
   <config:config-item config:name="AddParaSpacingToTableCells" config:type="boolean">true</config:config-item>
   <config:config-item config:name="CurrentDatabaseCommand" config:type="string"/>
   <config:config-item config:name="PrinterIndependentLayout" config:type="string">high-resolution</config:config-item>
   <config:config-item config:name="ApplyUserData" config:type="boolean">true</config:config-item>
   <config:config-item config:name="PrintFaxName" config:type="string"/>
   <config:config-item config:name="CurrentDatabaseDataSource" config:type="string"/>
   <config:config-item config:name="ClipAsCharacterAnchoredWriterFlyFrames" config:type="boolean">false</config:config-item>
   <config:config-item config:name="IsKernAsianPunctuation" config:type="boolean">false</config:config-item>
   <config:config-item config:name="SaveThumbnail" config:type="boolean">true</config:config-item>
   <config:config-item config:name="UseFormerTextWrapping" config:type="boolean">false</config:config-item>
   <config:config-item config:name="AddExternalLeading" config:type="boolean">true</config:config-item>
   <config:config-item config:name="AddParaTableSpacing" config:type="boolean">true</config:config-item>
   <config:config-item config:name="StylesNoDefault" config:type="boolean">false</config:config-item>
   <config:config-item config:name="ChartAutoUpdate" config:type="boolean">true</config:config-item>
   <config:config-item config:name="PrinterSetup" config:type="base64Binary"/>
   <config:config-item config:name="AddParaTableSpacingAtStart" config:type="boolean">true</config:config-item>
   <config:config-item config:name="Rsid" config:type="int">1161490</config:config-item>
   <config:config-item config:name="EmbeddedDatabaseName" config:type="string"/>
   <config:config-item config:name="FieldAutoUpdate" config:type="boolean">true</config:config-item>
   <config:config-item config:name="OutlineLevelYieldsNumbering" config:type="boolean">false</config:config-item>
   <config:config-item config:name="AlignTabStopPosition" config:type="boolean">true</config:config-item>
   <config:config-item config:name="CharacterCompressionType" config:type="short">0</config:config-item>
   <config:config-item config:name="PrinterName" config:type="string"/>
   <config:config-item config:name="SaveGlobalDocumentLinks" config:type="boolean">false</config:config-item>
   <config:config-item config:name="PrinterPaperFromSetup" config:type="boolean">false</config:config-item>
   <config:config-item config:name="UseFormerLineSpacing" config:type="boolean">false</config:config-item>
   <config:config-item config:name="AddParaLineSpacingToTableCells" config:type="boolean">true</config:config-item>
   <config:config-item config:name="UseFormerObjectPositioning" config:type="boolean">false</config:config-item>
   <config:config-item config:name="PrintGraphics" config:type="boolean">true</config:config-item>
   <config:config-item config:name="SurroundTextWrapSmall" config:type="boolean">false</config:config-item>
   <config:config-item config:name="ConsiderTextWrapOnObjPos" config:type="boolean">false</config:config-item>
   <config:config-item config:name="MsWordCompTrailingBlanks" config:type="boolean">false</config:config-item>
   <config:config-item config:name="TabAtLeftIndentForParagraphsInList" config:type="boolean">false</config:config-item>
   <config:config-item config:name="PrintRightPages" config:type="boolean">true</config:config-item>
   <config:config-item config:name="IgnoreFirstLineIndentInNumbering" config:type="boolean">false</config:config-item>
   <config:config-item config:name="RedlineProtectionKey" config:type="base64Binary"/>
   <config:config-item config:name="DoNotJustifyLinesWithManualBreak" config:type="boolean">false</config:config-item>
   <config:config-item config:name="PrintProspectRTL" config:type="boolean">false</config:config-item>
   <config:config-item config:name="PrintEmptyPages" config:type="boolean">true</config:config-item>
   <config:config-item config:name="DoNotResetParaAttrsForNumFont" config:type="boolean">false</config:config-item>
   <config:config-item config:name="AddFrameOffsets" config:type="boolean">false</config:config-item>
   <config:config-item config:name="IgnoreTabsAndBlanksForLineCalculation" config:type="boolean">false</config:config-item>
   <config:config-item config:name="LoadReadonly" config:type="boolean">false</config:config-item>
   <config:config-item config:name="DoNotCaptureDrawObjsOnPage" config:type="boolean">false</config:config-item>
   <config:config-item config:name="AddVerticalFrameOffsets" config:type="boolean">false</config:config-item>
   <config:config-item config:name="UnxForceZeroExtLeading" config:type="boolean">false</config:config-item>
   <config:config-item config:name="IsLabelDocument" config:type="boolean">false</config:config-item>
   <config:config-item config:name="TableRowKeep" config:type="boolean">false</config:config-item>
   <config:config-item config:name="RsidRoot" config:type="int">1161490</config:config-item>
   <config:config-item config:name="PrintHiddenText" config:type="boolean">false</config:config-item>
   <config:config-item config:name="ProtectForm" config:type="boolean">false</config:config-item>
   <config:config-item config:name="MsWordCompMinLineHeightByFly" config:type="boolean">false</config:config-item>
   <config:config-item config:name="BackgroundParaOverDrawings" config:type="boolean">false</config:config-item>
   <config:config-item config:name="SaveVersionOnClose" config:type="boolean">false</config:config-item>
   <config:config-item config:name="MathBaselineAlignment" config:type="boolean">true</config:config-item>
   <config:config-item config:name="SmallCapsPercentage66" config:type="boolean">false</config:config-item>
   <config:config-item config:name="CollapseEmptyCellPara" config:type="boolean">true</config:config-item>
   <config:config-item config:name="TabOverflow" config:type="boolean">true</config:config-item>
  </config:config-item-set>
 </office:settings>
 <office:scripts>
  <office:script script:language="ooo:Basic">
   <ooo:libraries xmlns:ooo="http://openoffice.org/2004/office" xmlns:xlink="http://www.w3.org/1999/xlink"/>
  </office:script>
 </office:scripts>
 <office:font-face-decls>
  <style:font-face style:name="Lohit Devanagari1" svg:font-family="&apos;Lohit Devanagari&apos;"/>
  <style:font-face style:name="Liberation Serif" svg:font-family="&apos;Liberation Serif&apos;" style:font-family-generic="roman" style:font-pitch="variable"/>
  <style:font-face style:name="Liberation Sans" svg:font-family="&apos;Liberation Sans&apos;" style:font-family-generic="swiss" style:font-pitch="variable"/>
  <style:font-face style:name="Lohit Devanagari" svg:font-family="&apos;Lohit Devanagari&apos;" style:font-family-generic="system" style:font-pitch="variable"/>
  <style:font-face style:name="Noto Sans CJK SC" svg:font-family="&apos;Noto Sans CJK SC&apos;" style:font-family-generic="system" style:font-pitch="variable"/>
  <style:font-face style:name="Noto Serif CJK SC" svg:font-family="&apos;Noto Serif CJK SC&apos;" style:font-family-generic="system" style:font-pitch="variable"/>
 </office:font-face-decls>
 <office:styles>
  <style:default-style style:family="graphic">
   <style:graphic-properties svg:stroke-color="#3465a4" draw:fill-color="#729fcf" fo:wrap-option="no-wrap" draw:shadow-offset-x="0.1181in" draw:shadow-offset-y="0.1181in" draw:start-line-spacing-horizontal="0.1114in" draw:start-line-spacing-vertical="0.1114in" draw:end-line-spacing-horizontal="0.1114in" draw:end-line-spacing-vertical="0.1114in" style:flow-with-text="false"/>
   <style:paragraph-properties style:text-autospace="ideograph-alpha" style:line-break="strict" style:writing-mode="lr-tb" style:font-independent-line-spacing="false">
    <style:tab-stops/>
   </style:paragraph-properties>
   <style:text-properties style:use-window-font-color="true" style:font-name="Liberation Serif" fo:font-size="12pt" fo:language="en" fo:country="US" style:letter-kerning="true" style:font-name-asian="Noto Serif CJK SC" style:font-size-asian="10.5pt" style:language-asian="zh" style:country-asian="CN" style:font-name-complex="Lohit Devanagari" style:font-size-complex="12pt" style:language-complex="hi" style:country-complex="IN"/>
  </style:default-style>
  <style:default-style style:family="paragraph">
   <style:paragraph-properties fo:orphans="2" fo:widows="2" fo:hyphenation-ladder-count="no-limit" style:text-autospace="ideograph-alpha" style:punctuation-wrap="hanging" style:line-break="strict" style:tab-stop-distance="0.4925in" style:writing-mode="page"/>
   <style:text-properties style:use-window-font-color="true" style:font-name="Liberation Serif" fo:font-size="12pt" fo:language="en" fo:country="US" style:letter-kerning="true" style:font-name-asian="Noto Serif CJK SC" style:font-size-asian="10.5pt" style:language-asian="zh" style:country-asian="CN" style:font-name-complex="Lohit Devanagari" style:font-size-complex="12pt" style:language-complex="hi" style:country-complex="IN" fo:hyphenate="false" fo:hyphenation-remain-char-count="2" fo:hyphenation-push-char-count="2" loext:hyphenation-no-caps="false"/>
  </style:default-style>
  <style:default-style style:family="table">
   <style:table-properties table:border-model="collapsing"/>
  </style:default-style>
  <style:default-style style:family="table-row">
   <style:table-row-properties fo:keep-together="auto"/>
  </style:default-style>
  <style:style style:name="Standard" style:family="paragraph" style:class="text"/>
  <style:style style:name="Heading" style:family="paragraph" style:parent-style-name="Standard" style:next-style-name="Text_20_body" style:class="text">
   <style:paragraph-properties fo:margin-top="0.1665in" fo:margin-bottom="0.0835in" loext:contextual-spacing="false" fo:keep-with-next="always"/>
   <style:text-properties style:font-name="Liberation Sans" fo:font-family="&apos;Liberation Sans&apos;" style:font-family-generic="swiss" style:font-pitch="variable" fo:font-size="14pt" style:font-name-asian="Noto Sans CJK SC" style:font-family-asian="&apos;Noto Sans CJK SC&apos;" style:font-family-generic-asian="system" style:font-pitch-asian="variable" style:font-size-asian="14pt" style:font-name-complex="Lohit Devanagari" style:font-family-complex="&apos;Lohit Devanagari&apos;" style:font-family-generic-complex="system" style:font-pitch-complex="variable" style:font-size-complex="14pt"/>
  </style:style>
  <style:style style:name="Text_20_body" style:display-name="Text body" style:family="paragraph" style:parent-style-name="Standard" style:class="text">
   <style:paragraph-properties fo:margin-top="0in" fo:margin-bottom="0.0972in" loext:contextual-spacing="false" fo:line-height="115%"/>
  </style:style>
  <style:style style:name="List" style:family="paragraph" style:parent-style-name="Text_20_body" style:class="list">
   <style:text-properties style:font-size-asian="12pt" style:font-name-complex="Lohit Devanagari1" style:font-family-complex="&apos;Lohit Devanagari&apos;"/>
  </style:style>
  <style:style style:name="Caption" style:family="paragraph" style:parent-style-name="Standard" style:class="extra">
   <style:paragraph-properties fo:margin-top="0.0835in" fo:margin-bottom="0.0835in" loext:contextual-spacing="false" text:number-lines="false" text:line-number="0"/>
   <style:text-properties fo:font-size="12pt" fo:font-style="italic" style:font-size-asian="12pt" style:font-style-asian="italic" style:font-name-complex="Lohit Devanagari1" style:font-family-complex="&apos;Lohit Devanagari&apos;" style:font-size-complex="12pt" style:font-style-complex="italic"/>
  </style:style>
  <style:style style:name="Index" style:family="paragraph" style:parent-style-name="Standard" style:class="index">
   <style:paragraph-properties text:number-lines="false" text:line-number="0"/>
   <style:text-properties style:font-size-asian="12pt" style:font-name-complex="Lohit Devanagari1" style:font-family-complex="&apos;Lohit Devanagari&apos;"/>
  </style:style>
  <text:outline-style style:name="Outline">
   <text:outline-level-style text:level="1" style:num-format="">
    <style:list-level-properties text:list-level-position-and-space-mode="label-alignment">
     <style:list-level-label-alignment text:label-followed-by="listtab"/>
    </style:list-level-properties>
   </text:outline-level-style>
   <text:outline-level-style text:level="2" style:num-format="">
    <style:list-level-properties text:list-level-position-and-space-mode="label-alignment">
     <style:list-level-label-alignment text:label-followed-by="listtab"/>
    </style:list-level-properties>
   </text:outline-level-style>
   <text:outline-level-style text:level="3" style:num-format="">
    <style:list-level-properties text:list-level-position-and-space-mode="label-alignment">
     <style:list-level-label-alignment text:label-followed-by="listtab"/>
    </style:list-level-properties>
   </text:outline-level-style>
   <text:outline-level-style text:level="4" style:num-format="">
    <style:list-level-properties text:list-level-position-and-space-mode="label-alignment">
     <style:list-level-label-alignment text:label-followed-by="listtab"/>
    </style:list-level-properties>
   </text:outline-level-style>
   <text:outline-level-style text:level="5" style:num-format="">
    <style:list-level-properties text:list-level-position-and-space-mode="label-alignment">
     <style:list-level-label-alignment text:label-followed-by="listtab"/>
    </style:list-level-properties>
   </text:outline-level-style>
   <text:outline-level-style text:level="6" style:num-format="">
    <style:list-level-properties text:list-level-position-and-space-mode="label-alignment">
     <style:list-level-label-alignment text:label-followed-by="listtab"/>
    </style:list-level-properties>
   </text:outline-level-style>
   <text:outline-level-style text:level="7" style:num-format="">
    <style:list-level-properties text:list-level-position-and-space-mode="label-alignment">
     <style:list-level-label-alignment text:label-followed-by="listtab"/>
    </style:list-level-properties>
   </text:outline-level-style>
   <text:outline-level-style text:level="8" style:num-format="">
    <style:list-level-properties text:list-level-position-and-space-mode="label-alignment">
     <style:list-level-label-alignment text:label-followed-by="listtab"/>
    </style:list-level-properties>
   </text:outline-level-style>
   <text:outline-level-style text:level="9" style:num-format="">
    <style:list-level-properties text:list-level-position-and-space-mode="label-alignment">
     <style:list-level-label-alignment text:label-followed-by="listtab"/>
    </style:list-level-properties>
   </text:outline-level-style>
   <text:outline-level-style text:level="10" style:num-format="">
    <style:list-level-properties text:list-level-position-and-space-mode="label-alignment">
     <style:list-level-label-alignment text:label-followed-by="listtab"/>
    </style:list-level-properties>
   </text:outline-level-style>
  </text:outline-style>
  <text:notes-configuration text:note-class="footnote" style:num-format="1" text:start-value="0" text:footnotes-position="page" text:start-numbering-at="document"/>
  <text:notes-configuration text:note-class="endnote" style:num-format="i" text:start-value="0"/>
  <text:linenumbering-configuration text:number-lines="false" text:offset="0.1965in" style:num-format="1" text:number-position="left" text:increment="5"/>
 </office:styles>
 <office:automatic-styles>
  <style:page-layout style:name="pm1">
   <style:page-layout-properties fo:page-width="8.5in" fo:page-height="11in" style:num-format="1" style:print-orientation="portrait" fo:margin-top="0.7874in" fo:margin-bottom="0.7874in" fo:margin-left="0.7874in" fo:margin-right="0.7874in" style:writing-mode="lr-tb" style:footnote-max-height="0in">
    <style:footnote-sep style:width="0.0071in" style:distance-before-sep="0.0398in" style:distance-after-sep="0.0398in" style:line-style="solid" style:adjustment="left" style:rel-width="25%" style:color="#000000"/>
   </style:page-layout-properties>
   <style:header-style/>
   <style:footer-style/>
  </style:page-layout>
 </office:automatic-styles>
 <office:master-styles>
  <style:master-page style:name="Standard" style:page-layout-name="pm1"/>
 </office:master-styles>
 <office:body>
  <office:text>
   <text:sequence-decls>
    <text:sequence-decl text:display-outline-level="0" text:name="Illustration"/>
    <text:sequence-decl text:display-outline-level="0" text:name="Table"/>
    <text:sequence-decl text:display-outline-level="0" text:name="Text"/>
    <text:sequence-decl text:display-outline-level="0" text:name="Drawing"/>
    <text:sequence-decl text:display-outline-level="0" text:name="Figure"/>
   </text:sequence-decls>
   <text:p text:style-name="Text_20_body">Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Euismod nisi porta lorem mollis aliquam ut porttitor leo a. Malesuada fames ac turpis egestas maecenas pharetra convallis. Amet justo donec enim diam vulputate ut pharetra sit. Duis at consectetur lorem donec massa sapien. Pulvinar sapien et ligula ullamcorper malesuada proin libero nunc. Dignissim sodales ut eu sem integer vitae. Est velit egestas dui id. Sem fringilla ut morbi tincidunt augue interdum. Vel facilisis volutpat est velit egestas dui. Lobortis mattis aliquam faucibus purus in massa tempor.</text:p>
   <text:p text:style-name="Text_20_body">Lobortis elementum nibh tellus molestie nunc. Faucibus interdum posuere lorem ipsum dolor sit amet consectetur. Fringilla phasellus faucibus scelerisque eleifend donec pretium vulputate sapien. Leo urna molestie at elementum eu facilisis sed odio morbi. Purus non enim praesent elementum facilisis leo. Non arcu risus quis varius quam quisque. Ultrices gravida dictum fusce ut placerat orci. Convallis a cras semper auctor neque vitae. Quisque non tellus orci ac auctor. Tellus in hac habitasse platea dictumst vestibulum rhoncus. Nisl purus in mollis nunc. Posuere lorem ipsum dolor sit amet consectetur adipiscing elit. Iaculis urna id volutpat lacus laoreet non. Arcu bibendum at varius vel pharetra vel turpis nunc. Turpis massa sed elementum tempus egestas. Aliquet nec ullamcorper sit amet risus nullam eget felis. Turpis egestas integer eget aliquet. Etiam erat velit scelerisque in dictum non consectetur a. In fermentum posuere urna nec tincidunt praesent semper feugiat nibh.</text:p>
   <text:p text:style-name="Text_20_body">Ut lectus arcu bibendum at varius vel pharetra. Eget nulla facilisi etiam dignissim diam. Vitae elementum curabitur vitae nunc sed velit dignissim sodales ut. A diam sollicitudin tempor id eu. Ultricies integer quis auctor elit. Feugiat sed lectus vestibulum mattis. Neque egestas congue quisque egestas. Tincidunt tortor aliquam nulla facilisi cras fermentum odio eu feugiat. Faucibus scelerisque eleifend donec pretium vulputate sapien nec. Lorem ipsum dolor sit amet. Id aliquet risus feugiat in ante metus dictum. Est lorem ipsum dolor sit amet consectetur adipiscing elit pellentesque. Turpis in eu mi bibendum neque egestas congue. Adipiscing elit pellentesque habitant morbi. Volutpat maecenas volutpat blandit aliquam etiam erat velit. Semper auctor neque vitae tempus quam pellentesque nec. Purus non enim praesent elementum facilisis. Fermentum odio eu feugiat pretium nibh ipsum. Commodo nulla facilisi nullam vehicula. Pellentesque habitant morbi tristique senectus et netus et.</text:p>
   <text:p text:style-name="Text_20_body">Praesent semper feugiat nibh sed pulvinar proin. Amet aliquam id diam maecenas ultricies mi eget mauris. Adipiscing elit pellentesque habitant morbi tristique senectus et netus et. Ornare quam viverra orci sagittis eu volutpat odio facilisis mauris. Volutpat sed cras ornare arcu. In eu mi bibendum neque. In hac habitasse platea dictumst vestibulum. Tortor at auctor urna nunc id cursus metus aliquam eleifend. Tristique senectus et netus et malesuada fames ac turpis. Quis vel eros donec ac odio tempor orci dapibus. Ultrices sagittis orci a scelerisque purus semper eget duis at. Sit amet consectetur adipiscing elit pellentesque habitant morbi tristique senectus. Pharetra vel turpis nunc eget lorem dolor. Metus aliquam eleifend mi in nulla posuere sollicitudin. Aliquet enim tortor at auctor urna nunc. Dolor purus non enim praesent elementum facilisis leo vel. Interdum velit euismod in pellentesque massa.</text:p>
  </office:text>
 </office:body>
</office:document>
""");

run(["/tmp/flat-odt", "/tmp/lorem.txt"]);


































