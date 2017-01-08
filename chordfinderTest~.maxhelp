{
	"patcher" : 	{
		"fileversion" : 1,
		"appversion" : 		{
			"major" : 7,
			"minor" : 3,
			"revision" : 1,
			"architecture" : "x64",
			"modernui" : 1
		}
,
		"rect" : [ 59.0, 104.0, 640.0, 480.0 ],
		"bglocked" : 0,
		"openinpresentation" : 0,
		"default_fontsize" : 12.0,
		"default_fontface" : 0,
		"default_fontname" : "Arial",
		"gridonopen" : 1,
		"gridsize" : [ 15.0, 15.0 ],
		"gridsnaponopen" : 1,
		"objectsnaponopen" : 1,
		"statusbarvisible" : 2,
		"toolbarvisible" : 1,
		"lefttoolbarpinned" : 0,
		"toptoolbarpinned" : 0,
		"righttoolbarpinned" : 0,
		"bottomtoolbarpinned" : 0,
		"toolbars_unpinned_last_save" : 0,
		"tallnewobj" : 0,
		"boxanimatetime" : 200,
		"enablehscroll" : 1,
		"enablevscroll" : 1,
		"devicewidth" : 0.0,
		"description" : "",
		"digest" : "",
		"tags" : "",
		"style" : "",
		"subpatcher_template" : "",
		"boxes" : [ 			{
				"box" : 				{
					"id" : "obj-21",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 321.25, 458.0, 105.0, 22.0 ],
					"style" : "",
					"text" : "print chromogram"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-20",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 22.0, 72.0, 426.0, 20.0 ],
					"style" : "",
					"text" : "A chord detection external for Max (MacOS) by Francesco Perticarari"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-19",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 22.0, 94.0, 426.0, 20.0 ],
					"style" : "",
					"text" : "Interpret input audio using an FFT analysis and return harmonical content",
					"textcolor" : [ 0.32549, 0.345098, 0.372549, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"border" : 0,
					"filename" : "helpdetails.js",
					"id" : "obj-5",
					"ignoreclick" : 1,
					"jsarguments" : [ "ChordID~" ],
					"maxclass" : "jsui",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 22.0, 24.0, 226.0, 46.0 ]
				}

			}
, 			{
				"box" : 				{
					"allowreorder" : 1,
					"clipheight" : 24.833333,
					"data" : 					{
						"clips" : [ 							{
								"filename" : "vibes-a1.aif",
								"filekind" : "audiofile",
								"loop" : 0,
								"content_state" : 								{
									"play" : [ 0 ],
									"pitchcorrection" : [ 0 ],
									"quality" : [ "basic" ],
									"speed" : [ 1.0 ],
									"timestretch" : [ 0 ],
									"slurtime" : [ 0.0 ],
									"originallength" : [ 0.0, "ticks" ],
									"formant" : [ 1.0 ],
									"formantcorrection" : [ 0 ],
									"followglobaltempo" : [ 0 ],
									"originallengthms" : [ 0.0 ],
									"originaltempo" : [ 120.0 ],
									"pitchshift" : [ 1.0 ],
									"basictuning" : [ 440 ],
									"mode" : [ "basic" ],
									"pitchshiftcent" : [ 0 ]
								}

							}
, 							{
								"filename" : "sho0630.aif",
								"filekind" : "audiofile",
								"loop" : 1,
								"content_state" : 								{
									"play" : [ 0 ],
									"pitchcorrection" : [ 0 ],
									"quality" : [ "basic" ],
									"speed" : [ 1.0 ],
									"timestretch" : [ 0 ],
									"slurtime" : [ 0.0 ],
									"originallength" : [ 0.0, "ticks" ],
									"formant" : [ 1.0 ],
									"formantcorrection" : [ 0 ],
									"followglobaltempo" : [ 0 ],
									"originallengthms" : [ 0.0 ],
									"originaltempo" : [ 120.0 ],
									"pitchshift" : [ 1.0 ],
									"basictuning" : [ 440 ],
									"mode" : [ "basic" ],
									"pitchshiftcent" : [ 0 ]
								}

							}
, 							{
								"filename" : "cherokee.aif",
								"filekind" : "audiofile",
								"loop" : 0,
								"content_state" : 								{
									"play" : [ 0 ],
									"pitchcorrection" : [ 0 ],
									"quality" : [ "basic" ],
									"speed" : [ 1.0 ],
									"timestretch" : [ 0 ],
									"slurtime" : [ 0.0 ],
									"originallength" : [ 0.0, "ticks" ],
									"formant" : [ 1.0 ],
									"formantcorrection" : [ 0 ],
									"followglobaltempo" : [ 0 ],
									"originallengthms" : [ 0.0 ],
									"originaltempo" : [ 120.0 ],
									"pitchshift" : [ 1.0 ],
									"basictuning" : [ 440 ],
									"mode" : [ "basic" ],
									"pitchshiftcent" : [ 0 ]
								}

							}
, 							{
								"filename" : "cello-f2.aif",
								"filekind" : "audiofile",
								"loop" : 1,
								"content_state" : 								{
									"play" : [ 0 ],
									"pitchcorrection" : [ 0 ],
									"quality" : [ "basic" ],
									"speed" : [ 1.0 ],
									"timestretch" : [ 0 ],
									"slurtime" : [ 0.0 ],
									"originallength" : [ 0.0, "ticks" ],
									"formant" : [ 1.0 ],
									"formantcorrection" : [ 0 ],
									"followglobaltempo" : [ 0 ],
									"originallengthms" : [ 0.0 ],
									"originaltempo" : [ 120.0 ],
									"pitchshift" : [ 1.0 ],
									"basictuning" : [ 440 ],
									"mode" : [ "basic" ],
									"pitchshiftcent" : [ 0 ]
								}

							}
, 							{
								"filename" : "jongly.aif",
								"filekind" : "audiofile",
								"loop" : 1,
								"content_state" : 								{
									"play" : [ 0 ],
									"pitchcorrection" : [ 0 ],
									"quality" : [ "basic" ],
									"speed" : [ 1.0 ],
									"timestretch" : [ 0 ],
									"slurtime" : [ 0.0 ],
									"originallength" : [ 0.0, "ticks" ],
									"formant" : [ 1.0 ],
									"formantcorrection" : [ 0 ],
									"followglobaltempo" : [ 0 ],
									"originallengthms" : [ 0.0 ],
									"originaltempo" : [ 120.0 ],
									"pitchshift" : [ 1.0 ],
									"basictuning" : [ 440 ],
									"mode" : [ "basic" ],
									"pitchshiftcent" : [ 0 ]
								}

							}
, 							{
								"filename" : "anton.aif",
								"filekind" : "audiofile",
								"loop" : 0,
								"content_state" : 								{
									"play" : [ 0 ],
									"pitchcorrection" : [ 0 ],
									"quality" : [ "basic" ],
									"speed" : [ 1.0 ],
									"timestretch" : [ 0 ],
									"slurtime" : [ 0.0 ],
									"originallength" : [ 0.0, "ticks" ],
									"formant" : [ 1.0 ],
									"formantcorrection" : [ 0 ],
									"followglobaltempo" : [ 0 ],
									"originallengthms" : [ 0.0 ],
									"originaltempo" : [ 120.0 ],
									"pitchshift" : [ 1.0 ],
									"basictuning" : [ 440 ],
									"mode" : [ "basic" ],
									"pitchshiftcent" : [ 0 ]
								}

							}
 ]
					}
,
					"id" : "obj-18",
					"maxclass" : "playlist~",
					"numinlets" : 1,
					"numoutlets" : 5,
					"outlettype" : [ "signal", "signal", "signal", "", "dictionary" ],
					"patching_rect" : [ 22.0, 134.0, 369.0, 155.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"format" : 6,
					"id" : "obj-15",
					"maxclass" : "flonum",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 456.0, 371.0, 50.0, 22.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-8",
					"maxclass" : "number",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 421.0, 497.5, 50.0, 22.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-7",
					"maxclass" : "number",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 221.5, 497.5, 90.0, 22.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-6",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 121.75, 458.0, 67.0, 22.0 ],
					"style" : "",
					"text" : "print chord"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-9",
					"maxclass" : "ezdac~",
					"numinlets" : 2,
					"numoutlets" : 0,
					"patching_rect" : [ 22.0, 497.5, 45.0, 45.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"floatoutput" : 1,
					"id" : "obj-16",
					"maxclass" : "slider",
					"min" : 0.00005,
					"mult" : 0.0001,
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 456.0, 202.5, 20.0, 140.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-14",
					"maxclass" : "button",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"patching_rect" : [ 301.0, 310.0, 24.0, 24.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-11",
					"maxclass" : "button",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"patching_rect" : [ 53.0, 351.0, 24.0, 24.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-10",
					"maxclass" : "number",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 215.0, 312.0, 50.0, 22.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-3",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 219.0, 351.0, 50.0, 22.0 ],
					"style" : "",
					"text" : "rate $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-12",
					"maxclass" : "button",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"patching_rect" : [ 146.5, 309.0, 24.0, 24.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-13",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 328.0, 351.0, 50.0, 22.0 ],
					"style" : "",
					"text" : "rms $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-1",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 5,
					"outlettype" : [ "", "", "", "", "" ],
					"patching_rect" : [ 22.0, 423.0, 92.0, 22.0 ],
					"style" : "",
					"text" : "achordID~.mxo"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-4",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 2,
					"outlettype" : [ "signal", "signal" ],
					"patching_rect" : [ 22.0, 588.0, 596.0, 22.0 ],
					"style" : "",
					"text" : "/Users/pesa/Documents/UNI/MC2/Ass_2/max-sdk/externals/myExternals/cppExternals-build/chordfinder~.mxo"
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"destination" : [ "obj-21", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-1", 3 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-6", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-1", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-7", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-1", 2 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-8", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-1", 4 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-9", 1 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-1", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-9", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-1", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-3", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-10", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-11", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-3", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-12", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-13", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-13", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-14", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-13", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-16", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-15", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-16", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-18", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-3", 0 ]
				}

			}
 ],
		"dependency_cache" : [ 			{
				"name" : "vibes-a1.aif",
				"bootpath" : "C74:/media/msp",
				"type" : "AIFF",
				"implicit" : 1
			}
, 			{
				"name" : "sho0630.aif",
				"bootpath" : "C74:/media/msp",
				"type" : "AIFF",
				"implicit" : 1
			}
, 			{
				"name" : "cherokee.aif",
				"bootpath" : "C74:/media/msp",
				"type" : "AIFF",
				"implicit" : 1
			}
, 			{
				"name" : "cello-f2.aif",
				"bootpath" : "C74:/media/msp",
				"type" : "AIFF",
				"implicit" : 1
			}
, 			{
				"name" : "jongly.aif",
				"bootpath" : "C74:/media/msp",
				"type" : "AIFF",
				"implicit" : 1
			}
, 			{
				"name" : "anton.aif",
				"bootpath" : "C74:/media/msp",
				"type" : "AIFF",
				"implicit" : 1
			}
, 			{
				"name" : "helpdetails.js",
				"bootpath" : "C74:/help/resources",
				"type" : "TEXT",
				"implicit" : 1
			}
, 			{
				"name" : "chordfinder~.mxo",
				"type" : "iLaX"
			}
 ],
		"autosave" : 0
	}

}
