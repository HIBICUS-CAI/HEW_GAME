//------------------------------------------------------------------------
// �t�@�C����: DataSyncer.h
// �@�\: �Q�[���Ɏg���f�[�^�x�[�X�̃f�[�^���܂Ƃ߂ĊǗ�����
//------------------------------------------------------------------------

#pragma once

/// <summary>
/// ���ʃe�[�u�����X�V�Ɏg����\����
/// </summary>
struct DATA_UPDATE_RANK
{
    int StageID;
    int Rank;

    DATA_UPDATE_RANK()
    {
        StageID = -1;
        Rank = -1;
    }

    DATA_UPDATE_RANK(int _stage, int _rank)
    {
        StageID = _stage;
        Rank = _rank;
    }

    int IsMeanful()
    {
        if (StageID != -1 && Rank != -1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
};

/// <summary>
/// �{�݃e�[�u�����X�V�Ɏg����\����
/// </summary>
struct DATA_UPDATE_BUILD
{
    int StageID;
    int BuildTypeCount[8];

    DATA_UPDATE_BUILD()
    {
        StageID = -1;
        for (int i = 0; i < 8; i++)
        {
            BuildTypeCount[i] = 0;
        }
    }

    DATA_UPDATE_BUILD(int _stage, int* _count)
    {
        StageID = _stage;
        for (int i = 0; i < 8; i++)
        {
            BuildTypeCount[i] = _count[i];
        }
    }

    int IsMeanful()
    {
        if (StageID != -1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
};

/// <summary>
/// HEW��p�̃f�[�^�x�[�X�ɐڑ�
/// </summary>
void ConnectToHewDatabase();

/// <summary>
/// HEW��p�̃f�[�^�x�[�X�ɂ̐ڑ������
/// </summary>
void CloseConnectToHewDatabase();

/// <summary>
/// ���܂��ڑ����ۂ����m�F
/// </summary>
void TestHewDatabaseConnect();

/// <summary>
/// �f�[�^�x�[�X����̒l�ۑ��������������
/// </summary>
void InitDataSyncerCountArray();

/// <summary>
/// ���ʃe�[�u�����X�V����
/// </summary>
/// <param name="data">���x�̌���</param>
void UpdateStageRankMT(DATA_UPDATE_RANK data);

/// <summary>
/// �{�݃e�[�u�����X�V����
/// </summary>
/// <param name="data">���x�̎{�ݏ��</param>
void UpdateStageBuildTypeMT(DATA_UPDATE_BUILD data);

/// <summary>
/// ���ʂƎ{�݃e�[�u������K�v�ȏ���ۑ�����
/// </summary>
/// <param name="stageID">���̃X�e�[�W�ԍ�</param>
void GetStageRankAndBuildCount(int stageID);

/// <summary>
/// ���ʃe�[�u�����X�V�p�̃X���b�h���쐬����
/// </summary>
void CreateUpdateStageRankThread();

/// <summary>
/// �{�݃e�[�u�����X�V�p�̃X���b�h���쐬����
/// </summary>
void CreateUpdateStageBuildThread();

/// <summary>
/// ���ʂƎ{�݃e�[�u������K�v�ȏ���ۑ��p�̃X���b�h���쐬����
/// </summary>
void CreateGetStageRankAndBuildThread();
