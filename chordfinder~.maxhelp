{
	"patcher" : 	{
		"fileversion" : 1,
		"appversion" : 		{
			"major" : 7,
			"minor" : 3,
			"revision" : 1,
			"architecture" : "x86",
			"modernui" : 1
		}
,
		"rect" : [ 177.0, 79.0, 742.0, 707.0 ],
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
					"id" : "obj-9",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 489.799988, 195.5, 245.0, 33.0 ],
					"style" : "",
					"text" : "rate <int>: set frame-rate for analysis of chromagrams (each frame is 512 samples)"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-8",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 532.0, 318.5, 160.0, 33.0 ],
					"style" : "",
					"text" : "setRMS <float>: set RMS threshold for analysis"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-7",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 528.0, 369.5, 150.0, 33.0 ],
					"style" : "",
					"text" : "Bang: output last chord detected"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-6",
					"linecount" : 17,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 22.0, 580.0, 704.0, 248.0 ],
					"style" : "",
					"text" : "OUTPUT:\n1 & 2: signal passthrough\n\n3: Chord name\n\n4: Chord ID \n    -this being a 12-bit string identifying the intervals of the chord  e.g: [ 1 0 0 0 1 0 0 01 0 0 0 ]\n    -it also contains information regarding the root note ( a number between 0 and 11, which has been multiplied by 10000 and added to the binary string represented as an integer)\n    -e.g: D7th would be root_note D = 2, * 10000 = 20000, + 2194 = 22194 Em root_note E = 4, * 10000 = 40000, + 2320 = 42320\n\n5: midi notes as a list\n\n6: flag (1 or 0) whether or not the signal is oud enough to tricgger the detection\n\n\n\n"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-27",
					"maxclass" : "toggle",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 599.0, 523.0, 24.0, 24.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-17",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 207.0, 508.0, 34.0, 22.0 ],
					"style" : "",
					"text" : "print"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-24",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 447.600006, 502.5, 122.0, 22.0 ],
					"style" : "",
					"text" : " 65 69 72 75"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-23",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 337.200012, 550.0, 50.0, 22.0 ],
					"style" : "",
					"text" : "52194"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-22",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 221.800003, 550.0, 50.0, 22.0 ],
					"style" : "",
					"text" : "F7th"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-2",
					"maxclass" : "ezdac~",
					"numinlets" : 2,
					"numoutlets" : 0,
					"patching_rect" : [ 22.0, 514.5, 45.0, 45.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-20",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 22.0, 72.0, 426.0, 33.0 ],
					"style" : "",
					"text" : "A chord detection external for Max (MacOS) by Francesco Perticarari\nCopyright (c) 2016-2017"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-19",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 22.0, 107.0, 426.0, 20.0 ],
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
					"jsarguments" : [ "Chordfinder~" ],
					"maxclass" : "jsui",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 22.0, 24.0, 312.0, 46.0 ]
				}

			}
, 			{
				"box" : 				{
					"allowreorder" : 1,
					"clipheight" : 21.142857,
					"data" : 					{
						"clips" : [ 							{
								"filename" : "vibes-a1.aif",
								"filekind" : "audiofile",
								"loop" : 0,
								"content_state" : 								{
									"quality" : [ "basic" ],
									"originaltempo" : [ 120.0 ],
									"originallengthms" : [ 0.0 ],
									"formantcorrection" : [ 0 ],
									"formant" : [ 1.0 ],
									"slurtime" : [ 0.0 ],
									"mode" : [ "basic" ],
									"timestretch" : [ 0 ],
									"speed" : [ 1.0 ],
									"followglobaltempo" : [ 0 ],
									"basictuning" : [ 440 ],
									"play" : [ 0 ],
									"originallength" : [ 0.0, "ticks" ],
									"pitchcorrection" : [ 0 ],
									"pitchshift" : [ 1.0 ],
									"pitchshiftcent" : [ 0 ]
								}

							}
, 							{
								"filename" : "sho0630.aif",
								"filekind" : "audiofile",
								"loop" : 1,
								"content_state" : 								{
									"quality" : [ "basic" ],
									"originaltempo" : [ 120.0 ],
									"originallengthms" : [ 0.0 ],
									"formantcorrection" : [ 0 ],
									"formant" : [ 1.0 ],
									"slurtime" : [ 0.0 ],
									"mode" : [ "basic" ],
									"timestretch" : [ 0 ],
									"speed" : [ 1.0 ],
									"followglobaltempo" : [ 0 ],
									"basictuning" : [ 440 ],
									"play" : [ 0 ],
									"originallength" : [ 0.0, "ticks" ],
									"pitchcorrection" : [ 0 ],
									"pitchshift" : [ 1.0 ],
									"pitchshiftcent" : [ 0 ]
								}

							}
, 							{
								"filename" : "/Users/pesa/Music/iTunes/iTunes Media/Music/Edward Chilvers/12 Etudes/01 C Minor 2_3_4_5.mp3",
								"filekind" : "audiofile",
								"loop" : 0,
								"content_state" : 								{
									"quality" : [ "basic" ],
									"originaltempo" : [ 120.0 ],
									"originallengthms" : [ 0.0 ],
									"formantcorrection" : [ 0 ],
									"formant" : [ 1.0 ],
									"slurtime" : [ 0.0 ],
									"mode" : [ "basic" ],
									"timestretch" : [ 0 ],
									"speed" : [ 1.0 ],
									"followglobaltempo" : [ 0 ],
									"basictuning" : [ 440 ],
									"play" : [ 0 ],
									"originallength" : [ 0.0, "ticks" ],
									"pitchcorrection" : [ 0 ],
									"pitchshift" : [ 1.0 ]
								}

							}
, 							{
								"filename" : "cello-f2.aif",
								"filekind" : "audiofile",
								"loop" : 1,
								"content_state" : 								{
									"quality" : [ "basic" ],
									"originaltempo" : [ 120.0 ],
									"originallengthms" : [ 0.0 ],
									"formantcorrection" : [ 0 ],
									"formant" : [ 1.0 ],
									"slurtime" : [ 0.0 ],
									"mode" : [ "basic" ],
									"timestretch" : [ 0 ],
									"speed" : [ 1.0 ],
									"followglobaltempo" : [ 0 ],
									"basictuning" : [ 440 ],
									"play" : [ 0 ],
									"originallength" : [ 0.0, "ticks" ],
									"pitchcorrection" : [ 0 ],
									"pitchshift" : [ 1.0 ],
									"pitchshiftcent" : [ 0 ]
								}

							}
, 							{
								"filename" : "/Users/pesa/Music/iTunes/Squarepusher - Squarepusher Theme.mp3",
								"filekind" : "audiofile",
								"loop" : 0,
								"content_state" : 								{
									"quality" : [ "basic" ],
									"originaltempo" : [ 120.0 ],
									"originallengthms" : [ 0.0 ],
									"formantcorrection" : [ 0 ],
									"formant" : [ 1.0 ],
									"slurtime" : [ 0.0 ],
									"mode" : [ "basic" ],
									"timestretch" : [ 0 ],
									"speed" : [ 1.0 ],
									"followglobaltempo" : [ 0 ],
									"basictuning" : [ 440 ],
									"play" : [ 0 ],
									"originallength" : [ 0.0, "ticks" ],
									"pitchcorrection" : [ 0 ],
									"pitchshift" : [ 1.0 ]
								}

							}
, 							{
								"filename" : "anton.aif",
								"filekind" : "audiofile",
								"loop" : 0,
								"content_state" : 								{
									"quality" : [ "basic" ],
									"originaltempo" : [ 120.0 ],
									"originallengthms" : [ 0.0 ],
									"formantcorrection" : [ 0 ],
									"formant" : [ 1.0 ],
									"slurtime" : [ 0.0 ],
									"mode" : [ "basic" ],
									"timestretch" : [ 0 ],
									"speed" : [ 1.0 ],
									"followglobaltempo" : [ 0 ],
									"basictuning" : [ 440 ],
									"play" : [ 0 ],
									"originallength" : [ 0.0, "ticks" ],
									"pitchcorrection" : [ 0 ],
									"pitchshift" : [ 1.0 ],
									"pitchshiftcent" : [ 0 ]
								}

							}
, 							{
								"filename" : "/Applications/Max.app/Contents/Resources/C74/media/msp/drumLoop.aif",
								"filekind" : "audiofile",
								"loop" : 0,
								"content_state" : 								{
									"quality" : [ "basic" ],
									"originaltempo" : [ 120.0 ],
									"originallengthms" : [ 0.0 ],
									"formantcorrection" : [ 0 ],
									"formant" : [ 1.0 ],
									"slurtime" : [ 0.0 ],
									"mode" : [ "basic" ],
									"timestretch" : [ 0 ],
									"speed" : [ 1.0 ],
									"followglobaltempo" : [ 0 ],
									"basictuning" : [ 440 ],
									"play" : [ 0 ],
									"originallength" : [ 0.0, "ticks" ],
									"pitchcorrection" : [ 0 ],
									"pitchshift" : [ 1.0 ]
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
					"patching_rect" : [ 22.0, 151.0, 369.0, 155.0 ],
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
					"patching_rect" : [ 475.100006, 273.0, 61.0, 22.0 ],
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
					"patching_rect" : [ 457.100006, 244.5, 105.0, 22.5 ],
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
					"patching_rect" : [ 571.599976, 271.0, 24.0, 24.0 ],
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
					"patching_rect" : [ 497.600006, 374.0, 24.0, 24.0 ],
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
					"patching_rect" : [ 432.299988, 159.0, 50.0, 22.0 ],
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
					"patching_rect" : [ 432.299988, 201.0, 50.0, 22.0 ],
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
					"patching_rect" : [ 489.799988, 159.0, 24.0, 24.0 ],
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
					"patching_rect" : [ 457.100006, 324.0, 70.0, 22.0 ],
					"style" : "",
					"text" : "setRMS $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-4",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 6,
					"outlettype" : [ "signal", "signal", "", "", "", "" ],
					"patching_rect" : [ 22.0, 466.0, 596.0, 22.0 ],
					"style" : "",
					"text" : "/Users/pesa/Documents/UNI/MC2/Ass_2/max-sdk/externals/myExternals/cppExternals-build/chordfinder~.mxo"
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"destination" : [ "obj-3", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-10", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-4", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 507.100006, 428.0, 31.5, 428.0 ],
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
					"destination" : [ "obj-4", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 466.600006, 425.5, 31.5, 425.5 ],
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
					"destination" : [ "obj-4", 1 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 119.0, 446.0, 608.5, 446.0 ],
					"source" : [ "obj-18", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-4", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-18", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-4", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 441.799988, 425.0, 31.5, 425.0 ],
					"source" : [ "obj-3", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-17", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-4", 2 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 1 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-4", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-4", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-22", 1 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-4", 2 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-23", 1 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-4", 3 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-24", 1 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-4", 4 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-27", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-4", 5 ]
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
				"name" : "01 C Minor 2_3_4_5.mp3",
				"bootpath" : "~/Music/iTunes/iTunes Media/Music/Edward Chilvers/12 Etudes",
				"type" : "Mp3 ",
				"implicit" : 1
			}
, 			{
				"name" : "cello-f2.aif",
				"bootpath" : "C74:/media/msp",
				"type" : "AIFF",
				"implicit" : 1
			}
, 			{
				"name" : "Squarepusher - Squarepusher Theme.mp3",
				"bootpath" : "~/Music/iTunes",
				"type" : "Mp3 ",
				"implicit" : 1
			}
, 			{
				"name" : "anton.aif",
				"bootpath" : "C74:/media/msp",
				"type" : "AIFF",
				"implicit" : 1
			}
, 			{
				"name" : "drumLoop.aif",
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
