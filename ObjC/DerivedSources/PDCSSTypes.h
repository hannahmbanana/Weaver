//    
//  PDCSSTypes.h
//  PonyDebuggerDerivedSources
//
//  Generated on 8/23/12
//
//  Licensed to Square, Inc. under one or more contributor license agreements.
//  See the LICENSE file distributed with this work for the terms under
//  which Square, Inc. licenses this file to you.
//
    
#import <Weaver/PDObject.h>
#import <Weaver/PDDebugger.h>
#import <Weaver/PDDynamicDebuggerDomain.h>

NS_ASSUME_NONNULL_BEGIN

typedef NSString PDCSSStyleSheetId;

// CSS rule collection for a single pseudo style.
@interface PDCSSPseudoIdRules : PDObject

// Pseudo style identifier (see <code>enum PseudoId</code> in <code>RenderStyleConstants.h</code>).
// Type: integer
@property (nonatomic, strong) NSNumber *pseudoId;

// CSS rules applicable to the pseudo style.
// Type: array
@property (nonatomic, strong) NSArray *rules;

@end


// Text range within a resource. All numbers are zero-based.
@interface PDCSSSourceRange : PDObject

// Start line of range.
// Type: integer
@property (nonatomic, strong) NSNumber *startLine;

// Start column of range (inclusive).
// Type: integer
@property (nonatomic, strong) NSNumber *startColumn;

// End line of range.
// Type: integer
@property (nonatomic, strong) NSNumber *endLine;

// End column of range (exclusive).
// Type: integer
@property (nonatomic, strong) NSNumber *endColumn;

@end


// CSS property declaration data.
@interface PDCSSProperty : PDObject

// The property name.
@property (nonatomic, strong) NSString *name;

// The property value.
@property (nonatomic, strong) NSString *value;

// Whether the property has \"!important\" annotation (implies <code>false</code> if absent).
// Type: boolean
@property (nonatomic, strong, nullable) NSNumber *important;

// Whether the property is implicit (implies <code>false</code> if absent).
// Type: boolean
@property (nonatomic, strong, nullable) NSNumber *implicit;

// The full property text as specified in the style.
@property (nonatomic, strong, nullable) NSString *text;

// Whether the property is understood by the browser (implies <code>true</code> if absent).
// Type: boolean
@property (nonatomic, strong, nullable) NSNumber *parsedOk;

// Whether the property is disabled by the user (present for source-based properties only).
// Type
@property (nonatomic, strong, nullable) NSNumber *disabled;

// The entire property range in the enclosing style declaration (if available).
@property (nonatomic, strong, nullable) PDCSSSourceRange *range;

+ (instancetype)propertyWithName:(NSString *)name value:(NSString *)value;

@end


@interface PDCSSShorthandEntry : PDObject

// Shorthand name.
@property (nonatomic, strong) NSString *name;

// Shorthand value.
@property (nonatomic, strong) NSString *value;

// Whether the property has \"!important\" annotation (implies <code>false</code> if absent).
// Type: boolean
@property (nonatomic, strong, nullable) NSNumber *important;

@end


// CSS style representation.
@interface PDCSSStyle : PDObject

// The css style sheet identifier (absent for user agent stylesheet and user-specified stylesheet rules) this rule came from.
@property (nonatomic, strong, nullable) PDCSSStyleSheetId *styleSheetId;

// CSS properties in the style.
@property (nonatomic, strong) NSArray<PDCSSProperty *> *cssProperties;

// Computed values for all shorthands found in the style.
@property (nonatomic, strong) NSArray<PDCSSShorthandEntry *> *shorthandEntries;

// Style declaration text (if available).
@property (nonatomic, strong, nullable) NSString *cssText;

// Style declaration range in the enclosing stylesheet (if available).
@property (nonatomic, strong, nullable) PDCSSSourceRange *range;

@end


// CSS rule collection for a single pseudo style.
@interface PDCSSInheritedStyleEntry : PDObject

// The ancestor node's inline style, if any, in the style inheritance chain.
@property (nonatomic, strong) PDCSSStyle *inlineStyle;

// CSS rules matching the ancestor node in the style inheritance chain.
// Type: array
@property (nonatomic, strong) NSArray *matchedCSSRules;

@end


// CSS style information for a DOM style attribute.
@interface PDCSSStyleAttribute : PDObject

// DOM attribute name (e.g. "width").
// Type: string
@property (nonatomic, strong) NSString *name;

// CSS style generated by the respective DOM attribute.
@property (nonatomic, strong) PDCSSStyle *style;

@end


// CSS stylesheet metainformation.
@interface PDCSSStyleSheetHeader : PDObject

// The stylesheet identifier.
@property (nonatomic, strong) NSString *styleSheetId;

// Owner frame identifier.
@property (nonatomic, strong) NSString *frameId;

// Stylesheet resource URL.
// Type: string
@property (nonatomic, strong) NSString *sourceURL;

// Stylesheet origin.
@property (nonatomic, strong) NSString *origin;

// Stylesheet title.
// Type: string
@property (nonatomic, strong) NSString *title;

// Denotes whether the stylesheet is disabled.
// Type: boolean
@property (nonatomic, strong) NSNumber *disabled;

@end


// CSS stylesheet contents.
@interface PDCSSStyleSheetBody : PDObject

// The stylesheet identifier.
@property (nonatomic, strong) NSString *styleSheetId;

// Stylesheet resource URL.
// Type: array
@property (nonatomic, strong) NSArray *rules;

// Stylesheet resource contents (if available).
@property (nonatomic, strong) NSString *text;

@end


// Data for a simple selector (these are delimited by commas in a selector list).
@interface PDCSSValue : PDObject

+ (instancetype)valueWithText:(NSString *)text;

// Selector text.
@property (nonatomic, strong) NSString *text;

// Selector range in the underlying resource (if available).
@property (nonatomic, strong, nullable) PDCSSSourceRange *range;

@end


// Selector list data.
@interface PDCSSSelectorList : PDObject

+ (instancetype)selectorListWithSelectors:(NSArray<PDCSSValue *> *)selectors;

// Selectors in the list.
@property (nonatomic, strong) NSArray<PDCSSValue *> *selectors;

// Rule selector text.
@property (nonatomic, strong) NSString *text;

@end


@interface PDCSSMediaQueryExpression : PDObject

// Media query expression value.
// Type: number
@property (nonatomic, strong) NSNumber *value;

// Media query expression units.
@property (nonatomic, strong) NSString *unit;

// Media query expression feature.
@property (nonatomic, strong) NSString *feature;

// The associated range of the value text in the enclosing stylesheet (if available).
@property (nonatomic, strong, nullable) PDCSSSourceRange *valueRange;

// Computed length of media query expression (if applicable).
// Type: number
@property (nonatomic, strong, nullable) NSNumber *computedLength;

@end


@interface PDCSSMediaQuery : PDObject

// Array of media query expressions.
@property (nonatomic, strong) NSArray<PDCSSMediaQueryExpression *> *expressions;

// Whether the media query condition is satisfied.
// Type: boolean
@property (nonatomic, strong) NSNumber *active;

@end


// CSS media query descriptor.
@interface PDCSSMedia : PDObject

// Media query text.
@property (nonatomic, strong) NSString *text;

// Source of the media query: "mediaRule" if specified by a @media rule, "importRule" if specified by an @import rule, "linkedSheet" if specified by a "media" attribute in a linked stylesheet's LINK tag, "inlineSheet" if specified by a "media" attribute in an inline stylesheet's STYLE tag.
@property (nonatomic, strong) NSString *source;

// URL of the document containing the media query description.
@property (nonatomic, strong, nullable) NSString *sourceURL;

// The associated rule (@media or @import) header range in the enclosing stylesheet (if available).
@property (nonatomic, strong, nullable) PDCSSSourceRange *range;

// Identifier of the stylesheet containing this object (if exists).
@property (nonatomic, strong, nullable) PDCSSStyleSheetId *parentStyleSheetId;

// Array of media queries.
@property (nonatomic, strong, nullable) NSArray<PDCSSMediaQuery *> *mediaList;

@end


typedef NSString PDCSSStyleSheetOrigin;
// for stylesheets injected via extension
#define PDCSSStyleSheetOriginInjected @"injected"
// for user-agent stylesheets
#define PDCSSStyleSheetOriginUserAgent @"user-agent"
// for stylesheets created by the inspector (i.e. those holding the "via inspector" rules)
#define PDCSSStyleSheetOriginInspector @"inspector"
// for regular stylesheets
#define PDCSSStyleSheetOriginRegular @"regular"

// CSS rule representation.
@interface PDCSSRule : PDObject

// The css style sheet identifier (absent for user agent stylesheet and user-specified stylesheet rules) this rule came from.
@property (nonatomic, strong, nullable) NSString *styleSheetId;

// Rule selector data.
@property (nonatomic, strong) PDCSSSelectorList *selectorList;

// Parent stylesheet's origin.
// Either of PDCSSStyleSheetOriginInjected, PDCSSStyleSheetOriginUserAgent, PDCSSStyleSheetOriginInspector or PDCSSStyleSheetOriginRegular
@property (nonatomic, strong) PDCSSStyleSheetOrigin *origin;

// Associated style declaration.
@property (nonatomic, strong) PDCSSStyle *style;

// Media list array (for rules involving media queries). The array enumerates media queries starting with the innermost one, going outwards.
@property (nonatomic, strong, nullable) NSArray<PDCSSMedia *> *media;

@end


// Match data for a CSS rule
@interface PDCSSRuleMatch : PDObject

// CSS rule in the match.
@property (nonatomic, strong) PDCSSRule *rule;

// Matching selector indices in the rule's selectorList selectors (0-based).
// Type: array of integers
@property (nonatomic, strong) NSArray<NSNumber *> *matchingSelectors;

@end


@interface PDCSSPropertyInfo : PDObject

// Property name.
// Type: string
@property (nonatomic, strong) NSString *name;

// Longhand property names.
// Type: array
@property (nonatomic, strong) NSArray *longhands;

@end


@interface PDCSSComputedStyleProperty : PDObject

// Computed style property name.
// Type: string
@property (nonatomic, strong) NSString *name;

// Computed style property value.
// Type: string
@property (nonatomic, strong) NSString *value;

@end


// CSS selector profile entry.
@interface PDCSSSelectorProfileEntry : PDObject

// CSS selector of the corresponding rule.
// Type: string
@property (nonatomic, strong) NSString *selector;

// URL of the resource containing the corresponding rule.
// Type: string
@property (nonatomic, strong) NSString *url;

// Selector line number in the resource for the corresponding rule.
// Type: integer
@property (nonatomic, strong) NSNumber *lineNumber;

// Total time this rule handling contributed to the browser running time during profiling (in milliseconds.)
// Type: number
@property (nonatomic, strong) NSNumber *time;

// Number of times this rule was considered a candidate for matching against DOM elements.
// Type: integer
@property (nonatomic, strong) NSNumber *hitCount;

// Number of times this rule actually matched a DOM element.
// Type: integer
@property (nonatomic, strong) NSNumber *matchCount;

@end


@interface PDCSSSelectorProfile : PDObject

// Total processing time for all selectors in the profile (in milliseconds.)
// Type: number
@property (nonatomic, strong) NSNumber *totalTime;

// CSS selector profile entries.
// Type: array
@property (nonatomic, strong) NSArray *data;

@end


// This object represents a region that flows from a Named Flow.
@interface PDCSSRegion : PDObject

// The "overset" attribute of a Named Flow.
// Type: string
@property (nonatomic, strong) NSString *regionOverset;

// The corresponding DOM node id.
@property (nonatomic, strong) NSNumber *nodeId;

@end


// This object represents a Named Flow.
@interface PDCSSNamedFlow : PDObject

// The document node id.
@property (nonatomic, strong) NSNumber *documentNodeId;

// Named Flow identifier.
// Type: string
@property (nonatomic, strong) NSString *name;

// The "overset" attribute of a Named Flow.
// Type: boolean
@property (nonatomic, strong) NSNumber *overset;

// An array of nodes that flow into the Named Flow.
// Type: array
@property (nonatomic, strong) NSArray *content;

// An array of regions associated with the Named Flow.
// Type: array
@property (nonatomic, strong) NSArray *regions;

@end

// A descriptor of operation to mutate style declaration text.
@interface PDCSSStyleDeclarationEdit : PDObject

// The css style sheet identifier.
@property (nonatomic, strong) PDCSSStyleSheetId *styleSheetId;

// The range of the style text in the enclosing stylesheet.
@property (nonatomic, strong) PDCSSSourceRange *range;

// New style text.
@property (nonatomic, strong) NSString *text;

@end

NS_ASSUME_NONNULL_END

