//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//     ANTLR Version: 4.11.2-SNAPSHOT
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

// Generated from XPathLexer.g4 by ANTLR 4.11.2-SNAPSHOT

// Unreachable code detected
#pragma warning disable 0162
// The variable '...' is assigned but its value is never used
#pragma warning disable 0219
// Missing XML comment for publicly visible type or member '...'
#pragma warning disable 1591
// Ambiguous reference in cref attribute
#pragma warning disable 419

using System;
using System.IO;
using System.Text;
using Antlr4.Runtime;
using Antlr4.Runtime.Atn;
using Antlr4.Runtime.Misc;
using DFA = Antlr4.Runtime.Dfa.DFA;

[System.CodeDom.Compiler.GeneratedCode("ANTLR", "4.11.2-SNAPSHOT")]
[System.CLSCompliant(false)]
public partial class XPathLexer : Lexer {
	protected static DFA[] decisionToDFA;
	protected static PredictionContextCache sharedContextCache = new PredictionContextCache();
	public const int
		TokenRef=1, RuleRef=2, Anywhere=3, Root=4, Wildcard=5, Bang=6, ID=7, String=8;
	public static string[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static string[] modeNames = {
		"DEFAULT_MODE"
	};

	public static readonly string[] ruleNames = {
		"Anywhere", "Root", "Wildcard", "Bang", "ID", "NameChar", "NameStartChar", 
		"String"
	};


	public XPathLexer(ICharStream input)
	: this(input, Console.Out, Console.Error) { }

	public XPathLexer(ICharStream input, TextWriter output, TextWriter errorOutput)
	: base(input, output, errorOutput)
	{
		Interpreter = new LexerATNSimulator(this, _ATN, decisionToDFA, sharedContextCache);
	}

	private static readonly string[] _LiteralNames = {
		null, null, null, "'//'", "'/'", "'*'", "'!'"
	};
	private static readonly string[] _SymbolicNames = {
		null, "TokenRef", "RuleRef", "Anywhere", "Root", "Wildcard", "Bang", "ID", 
		"String"
	};
	public static readonly IVocabulary DefaultVocabulary = new Vocabulary(_LiteralNames, _SymbolicNames);

	[NotNull]
	public override IVocabulary Vocabulary
	{
		get
		{
			return DefaultVocabulary;
		}
	}

	public override string GrammarFileName { get { return "XPathLexer.g4"; } }

	public override string[] RuleNames { get { return ruleNames; } }

	public override string[] ChannelNames { get { return channelNames; } }

	public override string[] ModeNames { get { return modeNames; } }

	public override int[] SerializedAtn { get { return _serializedATN; } }

	static XPathLexer() {
		decisionToDFA = new DFA[_ATN.NumberOfDecisions];
		for (int i = 0; i < _ATN.NumberOfDecisions; i++) {
			decisionToDFA[i] = new DFA(_ATN.GetDecisionState(i), i);
		}
	}
	public override void Action(RuleContext _localctx, int ruleIndex, int actionIndex) {
		switch (ruleIndex) {
		case 4 : ID_action(_localctx, actionIndex); break;
		}
	}
	private void ID_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 0: 
						String text = Text;
						if ( Char.IsUpper(text[0]) ) 
							Type = TokenRef;
						else 
							Type = RuleRef;
						 break;
		}
	}

	private static int[] _serializedATN = {
		4,0,8,50,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,
		2,7,7,7,1,0,1,0,1,0,1,1,1,1,1,2,1,2,1,3,1,3,1,4,1,4,5,4,29,8,4,10,4,12,
		4,32,9,4,1,4,1,4,1,5,1,5,3,5,38,8,5,1,6,1,6,1,7,1,7,5,7,44,8,7,10,7,12,
		7,47,9,7,1,7,1,7,1,45,0,8,1,3,3,4,5,5,7,6,9,7,11,0,13,0,15,8,1,0,2,5,0,
		48,57,95,95,183,183,768,879,8255,8256,13,0,65,90,97,122,192,214,216,246,
		248,767,880,893,895,8191,8204,8205,8304,8591,11264,12271,12289,55295,63744,
		64975,65008,65533,50,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,
		9,1,0,0,0,0,15,1,0,0,0,1,17,1,0,0,0,3,20,1,0,0,0,5,22,1,0,0,0,7,24,1,0,
		0,0,9,26,1,0,0,0,11,37,1,0,0,0,13,39,1,0,0,0,15,41,1,0,0,0,17,18,5,47,
		0,0,18,19,5,47,0,0,19,2,1,0,0,0,20,21,5,47,0,0,21,4,1,0,0,0,22,23,5,42,
		0,0,23,6,1,0,0,0,24,25,5,33,0,0,25,8,1,0,0,0,26,30,3,13,6,0,27,29,3,11,
		5,0,28,27,1,0,0,0,29,32,1,0,0,0,30,28,1,0,0,0,30,31,1,0,0,0,31,33,1,0,
		0,0,32,30,1,0,0,0,33,34,6,4,0,0,34,10,1,0,0,0,35,38,3,13,6,0,36,38,7,0,
		0,0,37,35,1,0,0,0,37,36,1,0,0,0,38,12,1,0,0,0,39,40,7,1,0,0,40,14,1,0,
		0,0,41,45,5,39,0,0,42,44,9,0,0,0,43,42,1,0,0,0,44,47,1,0,0,0,45,46,1,0,
		0,0,45,43,1,0,0,0,46,48,1,0,0,0,47,45,1,0,0,0,48,49,5,39,0,0,49,16,1,0,
		0,0,4,0,30,37,45,1,1,4,0
	};

	public static readonly ATN _ATN =
		new ATNDeserializer().Deserialize(_serializedATN);


}