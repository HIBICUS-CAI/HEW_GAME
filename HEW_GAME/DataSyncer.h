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
/// <param name="data">���x�̌��ʎw���̃|�C���^</param>
void UpdateStageRankMT(DATA_UPDATE_RANK* data);

/// <summary>
/// �{�݃e�[�u�����X�V����
/// </summary>
/// <param name="data">���x�̎{�ݏ��w���̃|�C���^</param>
void UpdateStageBuildTypeMT(DATA_UPDATE_BUILD* data);

/// <summary>
/// ���ʂƎ{�݃e�[�u������K�v�ȏ���ۑ�����
/// </summary>
/// <param name="stageID">���̃X�e�[�W�ԍ��w���̃|�C���^</param>
void GetStageRankAndBuildCount(int* stageID);

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

/// <summary>
/// ���ʃe�[�u�����X�V�p�̃X���b�h�����
/// </summary>
void CloseUpdateStageRankThread();

/// <summary>
/// �{�݃e�[�u�����X�V�p�̃X���b�h�����
/// </summary>
void CloseUpdateStageBuildThread();

/// <summary>
/// ���ʂƎ{�݃e�[�u������K�v�ȏ���ۑ��p�̃X���b�h�����
/// </summary>
void CloseGetStageRankAndBuildThread();

/// <summary>
/// �����N�f�[�^�w���̃|�C���^���擾
/// </summary>
/// <returns>�����N�f�[�^�w���̃|�C���^</returns>
DATA_UPDATE_RANK* GetUpdateRankAddr();

/// <summary>
/// �{�݃f�[�^�w���̃|�C���^���擾
/// </summary>
/// <returns>�{�݃f�[�^�w���̃|�C���^</returns>
DATA_UPDATE_BUILD* GetUpdateBuildAddr();

/// <summary>
/// �f�[�^�x�[�X�g�p�ł��邩�ۂ����擾
/// </summary>
/// <returns>�g�p�t���O</returns>
int CanUseDataBase();

/// <summary>
/// �f�[�^�x�[�X�������������N���擾
/// </summary>
/// <returns>�����N�z��</returns>
int* GetDBRankArray();

/// <summary>
/// �f�[�^�x�[�X���������{�݂��擾
/// </summary>
/// <returns>�{�ݔz��</returns>
int* GetDBBuildArray();

/// <summary>
/// �f�[�^�x�[�X�ɐڑ�����p�̃X�e�[�W�ԍ���ݒ�
/// </summary>
/// <param name="value">�X�e�[�W�ԍ�</param>
void SetDBStageArgument(int value);

/// <summary>
/// ���̌��ʂ͍ŐV���ۂ�
/// </summary>
/// <returns>�ŐV���ʃt���O</returns>
int IsDBResultNewest();
